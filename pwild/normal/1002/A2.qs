namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs: Qubit[], bits: Bool[]) : Unit {
        mutable prev = -1;
        for (i in 0..Length(qs)-1) {
            if (bits[i]) {
                if (prev == -1) {
                    H(qs[i]);
                } else {
                    CNOT(qs[prev],qs[i]);
                }
                set prev = i;
            }
        }
	}
}