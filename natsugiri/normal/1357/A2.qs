namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;
   
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[4]) {
            X(qs[1]);
            X(qs[2]);
            unitary(qs[0..1]);
            unitary(qs[2..3]);
            let m0 = M(qs[0]);
            let m1 = M(qs[1]);
            let m2 = M(qs[2]);
            let m3 = M(qs[3]);

            ResetAll(qs);
            if (m0 == Zero and m1 == One and m2 == One and m3 == Zero) {
                return 0;
			} elif (m0 == Zero and m1 == One and m2 == One and m3 == One) {
                return 1;
			} elif (m0 == One and m1 == One and m2 == One and m3 == Zero) {
                return 2;
			} else {
                return 3;            
			}
		}     
    }
}