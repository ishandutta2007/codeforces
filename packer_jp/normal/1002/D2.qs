namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : () {
        body {
            let nQubits = Length(x);
            for (i in 0..nQubits-1) {
                CNOT(x[i],y);
                if(b[i]==0){
                    X(y);
                }
            }
        }
    }

}