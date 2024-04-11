namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable result = 0;
        using (q = Qubit[2]) { 
            H(q[0]); // (0+1)*(0)
            CNOT(q[0], q[1]); // (00+11)
            Controlled unitary([q[0]], q[1]); // 00 - 11 if Z else 00+11
            CNOT(q[1], q[0]); // 0*(0-1) if Z else 0*(0+1)
            H(q[1]); // 01 if Z else 00
            if (M(q[1]) == One) {
                X(q[1]);
                set result = 0; 
            } else {
                set result = 1;
            }
        }
        return result;
    }
}