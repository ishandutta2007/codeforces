namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using (q = Qubit[2]) {
            X(q[1]);
            unitary(q);
            if (M(q[0]) == One) {
               set ret = 1;
            } else {}
            Reset(q[0]); Reset(q[1]);
        }
        return ret;
    }
}