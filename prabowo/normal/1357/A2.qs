namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((q0, q1) = (Qubit(), Qubit())) {
            X(q1);
            unitary([q0, q1]);

            if (Zero != M(q0)) {
                X(q0);
                if (Zero != M(q1)) {
                    X(q1);
                    return 2;
                } else {
                    return 3;
                }
            } else {
                X(q0);
                unitary([q0, q1]);
                X(q0);
                if (Zero != M(q1)) {
                    X(q1);
                    return 0;
                } else {
                    return 1;
                }
            }
        }
        return 0;
    }
}