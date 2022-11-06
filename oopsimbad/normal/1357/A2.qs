namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            let a = MResetZ(qs[1]) == One;
            Reset(qs[0]);
            X(qs[1]);
            unitary(qs);
            let b = MResetZ(qs[0]) == One;
            Reset(qs[1]);
            mutable ans = 2;
            if(!a && !b) {
                set ans = 0;
            }
            if(a && b) {
                set ans = 3;
            }
            if(a && !b) {
                set ans = 1;
            }
            return ans;
        }
        // your code here
    }
}