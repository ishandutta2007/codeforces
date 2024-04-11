namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
   
    operation Check (qs : Qubit[], y : Qubit, i : Int) : Unit {
        body (...) {
        let n = Length(qs);
        for (j in i..n-1) {
            CNOT(qs[j % i], qs[j]); 
            X(qs[j]); 
        }    
        (Controlled X)(qs[i..n-1], y);
        for (j in i..n-1) {
            X(qs[j]); 
            CNOT(qs[j % i], qs[j]); 
        }    
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(qs);
            using (a = Qubit[n - 1]) {
                   for (i in 1..n-1) {
                      Check(qs, a[i-1], i);
                   }
                   X(y);
                   (ControlledOnInt(0, X))(a, y);
                   for (i in 1..n-1) {
                      Check(qs, a[i-1], i);
                   }
            }

    	}


        adjoint auto;

    }

}