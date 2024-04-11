namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let nQubits = Length(qs);
            for (i in 0..nQubits - 1) {
                let ob = M(qs[i]);
                if((ob == One) != bits0[i]){
                    return 1;
                }
            }
            return 0;
        }
    }
}