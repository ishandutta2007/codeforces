namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        let A = unitary(2.0*PI(), _);
        using (qs = Qubit[2]) {
            H(qs[0]);
            (Controlled A)([qs[0]], qs[1]);
            H(qs[0]);
            X(qs[0]);
            let res = M(qs[0]);
            ResetAll(qs);
            return res == One ? 1 | 0;
        }
    }
}