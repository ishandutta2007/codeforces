namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            let result = M(qs[1]);
            ResetAll(qs);
            return result == One ? 0 | 1;
        }
    }
}