namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable result = 0;
        using (q = Qubit()) {
            H(q);
            unitary(q);
            H(q);
            if (M(q) == One) {
                X(q);
                set result = 1; 
            } else {
                set result = 0;
            }
        }
        return result;
    }
}