namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            if (M(qs[1]) == One) {
                set ans = ans + 1;
            }
            ResetAll(qs);
        }
        using (qs = Qubit[2]) {
            X(qs[1]);
            unitary(qs);
            if (M(qs[0]) == One) {
                set ans = ans + 2;
            }
            ResetAll(qs);
        }
        return ans;
    }
}