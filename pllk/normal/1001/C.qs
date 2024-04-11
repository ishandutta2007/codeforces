namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            H(qs[0]);
            for (i in 0..Length(qs)-2) {
                CNOT(qs[i],qs[i+1]);
            }
        }
    }
}