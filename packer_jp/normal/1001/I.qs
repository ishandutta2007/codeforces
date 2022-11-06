namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool {
        body {
            mutable resultArray = new Result[N];
            using (qs = Qubit[N]){
                using (q = Qubit[1]){
                    X(q[0]);
                    H(q[0]);

                    ApplyToEach(H, qs);

                    Uf(qs,q[0]);

                    ApplyToEach(H, qs); 
                    for (idx in 0..(N-1)) {
                        set resultArray[idx] = MResetZ(qs[idx]);
                    }

                    Reset(q[0]);
                }
            }
            return ForAll(IsResultZero, resultArray);
        }
    }

}