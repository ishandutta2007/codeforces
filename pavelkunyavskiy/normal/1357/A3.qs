namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using (q = Qubit()) {
           unitary(q);
           Z(q);
           unitary(q);
           if (M(q) == One) {
              set ret = 0;
           } else {
              set ret = 1;
           }
           Reset(q);
        }
        return ret;
    }
}