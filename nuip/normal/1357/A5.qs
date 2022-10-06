namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();
 
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable answer = 1;
        for(i in 1..10) {
            using (q = Qubit()) {
                mutable t = Round(PI()/theta);
                if(t == 0) {
                   set t = 1;
                }
                mutable th = 0.;
                for (j in 1..t) {
                    unitary(q);
                    set th = th + theta;
                }
 
                Ry(-th, q);
//DumpMachine();
                if (M(q) != Zero){
                    set answer = 0;
                }
                Reset(q);
            }
        }
        return answer;
    }
}