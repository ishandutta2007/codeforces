namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    // Distinguish Rz from R1
    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using ((q0, q1) = (Qubit(), Qubit())) {
            H(q0);
            Controlled unitary([q0], (6.283185307179586, q1));
            H(q0);

            if (Zero != M(q0)) {
                X(q0);
                return 0;
            }
        }
        return 1;
    }
}