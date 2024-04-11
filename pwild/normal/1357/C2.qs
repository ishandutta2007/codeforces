namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        using (anc = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                for (q in qs) {
                    (Controlled X)([q], anc);
                }
                let res = M(anc) == One ? 1 | 0;
                Reset(anc);
             } until (res == parity)
             fixup {
                 ResetAll(qs);
             }
        }
    }
}