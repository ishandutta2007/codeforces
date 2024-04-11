namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using (q = Qubit[2]) {
           X(q[1]);
           unitary(q);
           if (M(q[0]) == Zero) {
              Reset(q[1]);
              X(q[0]);
              unitary(q);
              if (M(q[1]) == Zero) { 
                 set ret = 0;
              } else {
                 set ret = 1;
              }
           } elif (M(q[1]) == One) {
              set ret = 2;
           } else {
              set ret = 3;
           }
           Reset(q[0]);
           Reset(q[1]);
        }
        return ret;
    }
}