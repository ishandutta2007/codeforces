namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
                mutable re = true;
        using (xs = Qubit[N]) {
            for(i in 0..N-1) {
                H(xs[i]);
            }
            using (y = Qubit()) {
                X(y);
                H(y);
                Uf(xs, y);
                for(i in 0..N-1) {
                    H(xs[i]);
                }
                for(i in 0..N-1) {
                    if(M(xs[i]) == One) {
                        set re = false;
                    }
                }
                Reset(y);
            }
            ResetAll(xs);
        }
                return re;
    }

}