namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : () {
        body {
            let nQubits = Length(qs);
            merge(qs, 0, nQubits);
        }
    }
    operation merge (qs : Qubit[], s : Int, n : Int) : () {
        body {
            if(n == 1){
                X(qs[s]);
                return ();
            }
            merge(qs, s, n/2);
            for (i in 0..n/2-1) {
                (Controlled H)([qs[s+i]],(qs[s+i+n/2]));
                CNOT(qs[s+i+n/2],qs[s+i]);
            }
        }
    }

}