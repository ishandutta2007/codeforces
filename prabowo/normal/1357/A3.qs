namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            unitary(q);
            X(q);
            unitary(q);

            if (Zero != M(q)) {
                X(q);
                return 1;
            }
        }
        return 0;
    }
}