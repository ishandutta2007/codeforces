namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs: Qubit[]) : Unit {
        ApplyToEach(H,qs);
	}
}