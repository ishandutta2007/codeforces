namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            (Controlled unitary)([q[0]], q[1]);
            (Controlled unitary)([q[0]], q[1]);
            CNOT(q[1], q[0]);
            H(q[1]);
            let r1 = M(q[1]); // Zero -> Y, One -> XZ
            ResetAll(q);

            H(q[0]);
            CNOT(q[0], q[1]);
            (Controlled unitary)([q[0]], q[1]);
            if (r1 == Zero) {
              (Controlled Adjoint Y)([q[0]], q[1]);
            } else {
              (Controlled Adjoint X)([q[0]], q[1]);
              (Controlled Adjoint Z)([q[0]], q[1]);
            }
            CNOT(q[1], q[0]);
            H(q[1]);

            let r2 = M(q[1]);


            if (r1 == Zero and r2 == Zero) {
               set ret = 0;  
            } elif (r1 == Zero and r2 == One) {
               set ret = 2;  
            } elif (r1 == One and r2 == Zero) {
               set ret = 3;  
            } elif (r1 == One and r2 == One) {
               set ret = 1;  
            }
            ResetAll(q);
        }
        return ret;
    }
}