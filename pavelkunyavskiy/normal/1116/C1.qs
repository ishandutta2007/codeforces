namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[], y : Qubit) : Unit {
        body (...) {
	        let n = Length(qs);
        	using (a = Qubit[n - 1]) {
	            for (i in 0..n-2) {
        	       CNOT(qs[i], a[i]);
	               CNOT(qs[i+1], a[i]);
        	    }
	            Controlled X(a, y);
        	    for (i in 0..n-2) {
	               CNOT(qs[i+1], a[i]);
        	       CNOT(qs[i], a[i]);
	            }
        	}
	}
        adjoint auto;
    }

}