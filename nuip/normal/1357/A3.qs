namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            H(q);
            unitary(q);
            H(q);
            unitary(q);
            let ans = (M(q) == One ? 1 | 0);
            Reset(q);
            return ans;
        }
    }

}