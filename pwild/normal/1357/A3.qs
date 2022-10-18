namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            unitary(q);
            X(q);
            unitary(q);
            let res = M(q);
            Reset(q);
            return res == One ? 1 | 0;
        }
    }
}