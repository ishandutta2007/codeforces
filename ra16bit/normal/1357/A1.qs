namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs=Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            if (M(qs[1]) == One) {
                ResetAll(qs);
                return 0;
            } else {
				ResetAll(qs);
                return 1;
            }
        }
    }

}