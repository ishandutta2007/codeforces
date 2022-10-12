namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    // Distinguish Z from -Z
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using ((q0, q1) = (Qubit(), Qubit())) {
            H(q0);
            Controlled unitary([q0], q1);
            H(q0);

            if (M(q0) != Zero) {
                X(q0);
                return 1;
            }
        }
        return 0;
    }
}