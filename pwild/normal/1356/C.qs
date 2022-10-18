namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (qs : Qubit[]) : Unit {
        using (anc = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                (Controlled X)(qs, anc);
                let res = M(anc);
                Reset(anc);
            } until (res == Zero)
            fixup {
                ResetAll(qs);
            }
            ApplyToEach(X, qs);
        }
    }
}