namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs: Qubit[]) : Int {
        ApplyToEach(H,qs);
        
        mutable res = 0;
        if (M(qs[0]) == One) {
            set res = res + 2;
        }
        if (M(qs[1]) == One) {
            set res = res + 1;
        }
        return res;
	}
}