namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (ang: Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        mutable times = 1;
        mutable aang = ang;
        set times = Floor(PI() / aang);
        using (q = Qubit()) {
           for (i in 0..10) {
              for (j in 0..times-1) {
                unitary(q);
              }
              if (M(q) == One) {
                set ret = 1;
                X(q);
              }    
           }
        }
        return ret;
    }
}