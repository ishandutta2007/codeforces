namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        using (q = Qubit()) {
            ApplyToEach(H, qs);
            for(q2 in qs) {
                Controlled X([q2],q);
            }
            if(MResetZ(q) == One) {
                if(parity == 0) {
                    X(qs[0]);
                }
            } else {
                if(parity == 1) {
                    X(qs[1]);
                }
            }
        }
    }
}