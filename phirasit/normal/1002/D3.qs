namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            (Controlled X)(x, y);
            for (i in 0 .. Length(x)-1) {
                X(x[i]);
                (Controlled X)(x, y);
                X(x[i]);
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