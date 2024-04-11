namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        using (q = Qubit()) {
        let n = Length(qs);
        for(i in 1..n-1) {
            H(qs[i]);
            Controlled X(qs[i..i], qs[0]);
        }
        if (parity == 1) {
            X(q);
        }
        Controlled X([q], qs[0]);
        Reset(q);
        }
    }
}