namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            H(qs[0]);
            let nQubits = Length(qs);
            for (i in 1..nQubits - 1) {
                CNOT(qs[0],qs[i]);
            }
        }
    }
}