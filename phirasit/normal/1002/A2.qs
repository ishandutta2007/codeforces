namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            H(qs[0]);
            for (i in 1 .. Length(qs)-1) {
                if (bits[i] == true) {
                    CNOT(qs[0], qs[i]);
                }
            }
        }
    }

    operation Test () : () 
    {
        body 
        {
            using (qs = Qubit[4]) 
            {
                Solve(qs, [true; true; true; true]);
                DumpRegister((), qs);
                ResetAll(qs);
            }
        }
    }
}