namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs: Qubit[]) : Unit {
        let n = Length(qs);
        let J = Ry(0.95,_);
        for (k in 0..n-1) {
            ApplyToEach((Controlled J)([qs[k]],_),qs[0..k-1]);
        }
	}
}