namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable result = 0;
        using (q = Qubit[2]) {
            unitary(q);
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