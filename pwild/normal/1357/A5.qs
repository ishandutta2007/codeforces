namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // maximal n such that n*theta <= PI
        let n = Floor(PI()/theta);
        using (q = Qubit()) {
            mutable found = 0;
            for (k in 0..10) {
                for (i in 1..n) {
                    unitary(q);
                }
                let res = MResetZ(q);
                set found += (res == One ? 1 | 0);
            }
            return found > 0 ? 1 | 0;
        }
    }
}