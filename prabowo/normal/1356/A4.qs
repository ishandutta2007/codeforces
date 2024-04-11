namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    // Distinguish IX from CNOT
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((q0, q1) = (Qubit(), Qubit())) {
            if (Zero != M(q0)) { X(q0); }
            if (One != M(q1)) { X(q1); }

            H(q0); H(q1);
            unitary([q0, q1]);
            H(q0);

            if (Zero != M(q1)) { X(q1); }
            if (Zero != M(q0)) {
                X(q0);
                return 1;
            }
        }
        return 0;
    }
}