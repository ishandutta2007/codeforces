namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (qs : Qubit[]) : Unit {
        using(q = Qubit()) {
            mutable stop = false;
            repeat {
                H(qs[0]); H(qs[1]);
                Controlled X(qs,q);
                if(MResetZ(q) == One) {
                    ResetAll(qs);
                } else {
                    set stop = true;
                }
            } until(stop);
            X(qs[0]); X(qs[1]);
        }
    }
}