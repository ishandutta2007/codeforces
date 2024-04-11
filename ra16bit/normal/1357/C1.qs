namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            repeat {
                ResetAll(qs);
                ApplyToEach(H, qs);
                Controlled X(qs, q);
                let r = MResetZ(q);
            }
            until (r == Zero);
        }
    }
}