namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], bits : Bool[]) : () {
        body {
            let nQubits = Length(qs);
            mutable idx = -1;
            for (i in 0..nQubits - 1) {
                if(bits[i]){
                    if(idx == -1){
                        H(qs[i]);
                        set idx = i;
                    }else{
                        CNOT(qs[idx], qs[i]);
                    }
                }
            }
        }
    }

}