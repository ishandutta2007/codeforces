namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable idx = 0;
            for (i in 0 .. Length(qs)-1) {
                if (bits0[i] != bits1[i]) {
                    set idx = i;
                }
            }

            H(qs[idx]);

            for (i in 0 .. Length(qs)-1) {
                if (i != idx) {
                    if (bits0[idx] == false) {
                        X(qs[idx]);
                    }
                    if (bits0[i] == true) {
                        CNOT(qs[idx], qs[i]);
                    }
                    if (bits0[idx] == false) {
                        X(qs[idx]);
                    }
                    
                    if (bits1[idx] == false) {
                        X(qs[idx]);
                    }
                    if (bits1[i] == true) {
                        CNOT(qs[idx], qs[i]);
                    }
                    if (bits1[idx] == false) {
                        X(qs[idx]);
                    }
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
                Solve(qs, [true; true; true; true], [true; true; true; true]);
                DumpRegister((), qs);
                ResetAll(qs);
            }
        }
    }
}