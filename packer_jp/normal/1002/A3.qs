namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : () {
        body {
            let nQubits = Length(qs);
            mutable idx = -1;
            for (i in 0..nQubits - 1) {
                if(bits0[i]&&bits1[i]){
                    X(qs[i]);
                }
                if(bits0[i]!=bits1[i]){
                    if(idx == -1){
                        H(qs[i]);
                        set idx = i;
                    }else{
                        CNOT(qs[idx], qs[i]);
                        if(bits0[idx]!=bits0[i]){
                            X(qs[i]);
                        }
                    }
                }
            }
        }
    }

}