namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using (q = Qubit[2]) {
           H(q[0]); 
	   CNOT(q[0], q[1]);
           (Controlled unitary)([q[0]], (2.0 * PI(), q[1]));
	   CNOT(q[1], q[0]);
           H(q[1]);
           if (M(q[1]) == One) {
              set ret = 0;
           } else {
              set ret = 1;
           }
           ResetAll(q);
        }
        return ret;
    }
}