namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            H(qs[0]);
		for (i in 1..Length(qs)-1) {
			CNOT(qs[i-1], qs[i]);
		}
        }
    }
}