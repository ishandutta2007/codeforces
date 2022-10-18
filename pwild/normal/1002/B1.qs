namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs: Qubit[]) : Int {
        mutable res = 0;
        for (i in 0..Length(qs)-1) {
            if (M(qs[i]) == One) {
                set res = 1;
            }
        }
        return res;
	}
}