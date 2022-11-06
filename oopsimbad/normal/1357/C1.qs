namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
 
    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        using(q = Qubit()) {
            mutable stop = false;
            Reset(q);
            repeat {
                mutable found = false;
                ApplyToEach(H, qs);
                Controlled X(qs, q);
                if(MResetZ(q) == Zero) {
                    set stop = true;
                } else {
                    ResetAll(qs);
                }
                Reset(q);
            } until(stop);
        }
        // your code here
    }
}