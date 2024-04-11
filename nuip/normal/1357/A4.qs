namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();
    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using ((q, p) = (Qubit(), Qubit())) {
            H(p);
            Controlled Rz([p], (-2.0*PI(), q));
            Controlled unitary([p], (2.0*PI(), q));
            Reset(q);
            return MResetX(p) == Zero ? 0 | 1;
        }
    }
}