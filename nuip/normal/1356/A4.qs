namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            unitary(qs);
            let re = (M(qs[1]) == One) ? 0 | 1; 
            ResetAll(qs);
            return re;
        }
    }
}