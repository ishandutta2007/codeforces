namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int {
        body {
            let nQubits = Length(qs);
            for (i in 0..nQubits-1) {
                if(M(qs[i]) == One){
                    return 1;
                }
            }
            return 0;
        }
    }

}