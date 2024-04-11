namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation count (qs : Qubit[], a : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
                for (i in 0..n-1) {
                    (Controlled X)([qs[i], a[1]], a[0]);
                    (Controlled X)([qs[i], a[0]], a[1]);
 		    CNOT(qs[i], a[0]);
                }
        }
        adjoint auto;
    }
   
    operation Solve (qs : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(qs);
            using (a = Qubit[2]) {
                count(qs, a);

                (ControlledOnInt(0, X))(a, y);

                (Adjoint count)(qs, a);

            }

    	}


        adjoint auto;

    }

}