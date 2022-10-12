namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    // Distinguish I from Z
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            if (Zero != M(q)) {
                X(q);
            }
            H(q);
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