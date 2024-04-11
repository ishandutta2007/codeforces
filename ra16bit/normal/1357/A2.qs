namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs=Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            if (M(qs[1]) == One) {
                if (M(qs[0]) == One) {
                    ResetAll(qs);
                    return 1;
                } else {
                    ResetAll(qs);
                    return 3;
                }
            } else {
				ResetAll(qs);
                X(qs[1]);
				unitary(qs);
                if (M(qs[0]) == One) {
                    ResetAll(qs);
                    return 2;
                } else {
                    ResetAll(qs);
                    return 0;
                }
            }
        }
    }

}