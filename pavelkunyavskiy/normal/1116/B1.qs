namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation My (q0 : Qubit, q1 : Qubit) : Unit {
         body (...) {
            Ry(1.9106332362490184, q0);
            (Controlled H)([q0], q1);
            X(q1); 
            CNOT(q1, q0);
         }
         adjoint auto;
         controlled auto;
    }

    operation Solve (qs : Qubit[]) : Int {
        Z(qs[1]); Z(qs[2]);
        CNOT(qs[2], qs[1]);
        H(qs[2]); 
        (Controlled H)([qs[0]], qs[2]);
        CNOT(qs[2], qs[1]);
        S(qs[2]);

        CNOT(qs[0], qs[2]);
        CNOT(qs[1], qs[2]);

        (Controlled H)([qs[0]], qs[1]);

        (ControlledOnInt(0, X))([qs[0], qs[1]], qs[2]);

        (Adjoint (Controlled My))([qs[2]], (qs[0], qs[1]));

        H(qs[2]);
        let r = M(qs[2]);
        if (r == One) {
           return 1;
        }
        return 0;
    }
}