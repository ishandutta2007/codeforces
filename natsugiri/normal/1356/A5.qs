namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            Controlled unitary(qs[0..0], qs[1]);
            H(qs[0]);
            let m = M(qs[0]);
            ResetAll(qs);
            if (m == Zero) {
                return 0;
			} else {
                return 1;     
			}
		}
    }
}