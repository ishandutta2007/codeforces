namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            unitary(q[1]);
            CNOT(q[1], q[0]);
            H(q[1]);
            let r1 = M(q[0]);
            let r2 = M(q[1]);
            if (r1 == Zero and r2 == Zero) {
               set ret = 0;  
            } elif (r1 == One and r2 == Zero) {
               set ret = 1;  
            } elif (r1 == One and r2 == One) {
               set ret = 2;  
            } elif (r1 == Zero and r2 == One) {
               set ret = 3;  
            }
            ResetAll(q);
        }
        return ret;
    }
}