namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();

    operation Solve(qs : Qubit[]) : Unit {
        let n = Length(qs);
        using (q = Qubit()) {
            repeat {
                for(i in 0..n-1) {
                    H(qs[i]);
                }
                Controlled X(qs, q);
            }
            until (M(q) == Zero)
            fixup {
                ResetAll(qs + [q]);
            }
        }
    }
}