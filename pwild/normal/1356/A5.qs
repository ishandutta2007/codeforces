namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            (Controlled unitary)([qs[0]], qs[1]);
            H(qs[0]);
            let res = M(qs[0]);
            ResetAll(qs);
            return res == One ? 1 | 0;
        }
    }
}