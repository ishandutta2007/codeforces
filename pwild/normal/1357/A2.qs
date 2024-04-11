namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[1]);
            unitary(qs);
            let a = M(qs[0]);
            ResetAll(qs);
            
            X(qs[0]);
            unitary(qs);
            let b = M(qs[1]);
            ResetAll(qs);
            
            return (a == One ? 2 | 0) + (b == One ? 1 | 0);
        }
    }
}