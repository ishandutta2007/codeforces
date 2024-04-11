namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;
   
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[0]);
            X(qs[1]);
            unitary(qs);
            let m = M(qs[0]);
            ResetAll(qs);
            if (m == Zero) {
				return 1;
            } else {
                return 0;
			}
		}     
    }
}