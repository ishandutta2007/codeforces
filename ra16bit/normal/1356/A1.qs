namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q=Qubit()) {
            unitary(q);
            if (M(q) == One) {
                Reset(q);
                return 1;
            } else {
                return 0;
            }
        }
    }

}