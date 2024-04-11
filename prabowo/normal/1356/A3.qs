namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    // Distinguish Z from S
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            if (Zero != M(q)) {
                X(q);
            }
            H(q);
            unitary(q);
            unitary(q);
            H(q);

            if (Zero != M(q)) {
                X(q);
                return 1;
            }
        }
        return 0;
    }
}