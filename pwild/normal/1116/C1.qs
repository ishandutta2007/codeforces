namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x: Qubit[], y: Qubit) : Unit {
        body (...) {
            let n = Length(x);
            for (i in n-1..-1..1) {
                CNOT(x[i-1],x[i]);
            }
            
            Controlled X(x[1..n-1],y);

            for (i in 1..n-1) {
                CNOT(x[i-1],x[i]);
            }
        }
        adjoint auto;
	}
}