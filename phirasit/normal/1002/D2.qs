namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            for (i in 0 .. Length(x)-1) {
                if (b[i] == 1) {
                    CNOT(x[i], y);
                } else {
                    X(x[i]);
                    CNOT(x[i], y);
                    X(x[i]);
                }
            }
        }
    }

    // operation Test () : () 
    // {
    //     body 
    //     {
    //         using (qs = Qubit[2]) 
    //         {
    //             let ans = Solve(qs);
    //             DumpRegister((), qs);
    //             ResetAll(qs);
    //         }
    //     }
    // }
}