namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (n: Int, Uf: ((Qubit[], Qubit) => Unit)): Bool {
        mutable res = true;
        using ((x,y) = (Qubit[n],Qubit())) {
            ApplyToEach(H,x);
            X(y);
            H(y);
            Uf(x,y);
            ApplyToEach(H,x);
            
            for (q in x) {
                if (M(q) == One) {
                    set res = false;
                }
            }
            ResetAll(x);
            Reset(y);
        }
        return res;
	}
}