namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (tmp = Qubit[2]) {
            unitary(tmp);
            if (M(tmp[1]) == One) {
                ResetAll(tmp);
                return 0;
            } else {
                ResetAll(tmp);
                return 1;
            }
        }
    }

}