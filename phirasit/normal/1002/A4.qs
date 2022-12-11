namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            if (Length(qs) == 1) {
                X(qs[0]);
            } else {
                let mid = Length(qs) / 2;
                Solve(qs[0..mid-1]);
                for (i in 0 .. mid-1) {
                    (Controlled H)(qs[i..i], qs[i + mid]);
                    CNOT(qs[i + mid], qs[i]);
                }
            }
        }
    }

    operation Test () : () 
    {
        body 
        {
            using (qs = Qubit[2]) 
            {
                Solve(qs);
                DumpRegister((), qs);
                ResetAll(qs);
            }
        }
    }
}