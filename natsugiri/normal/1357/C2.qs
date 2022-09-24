namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        for (i in 1..Length(qs)-1) {
            H(qs[i]);
            CNOT(qs[i], qs[0]);
		}
        if (parity == 1) {
            X(qs[0]);  
		}
    }
}