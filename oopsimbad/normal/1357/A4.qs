namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            H(q[0]);
            Controlled unitary([q[0]], (3.1415926535897932384264338327950288*2.0, q[1]));
            H(q[0]);
            return MResetZ(q[0]) == One ? 0 | 1;
        }
        // your code here
    }
}