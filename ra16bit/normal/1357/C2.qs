namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        ResetAll(qs);
        for (index in 1 .. Length(qs) - 1) {
            H(qs[index]);
            CNOT(qs[index], qs[0]);
        }
        if (parity == 1) {
            X(qs[0]);
        }
    }
}