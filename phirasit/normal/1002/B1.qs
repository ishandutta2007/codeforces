namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable ans = 0;
            for (i in 0 .. Length(qs)-1) {
                if (M(qs[i]) == One) {
                    set ans = 1;
                }
            }
            return ans;
        }
    }

    operation Test () : () 
    {
        body 
        {
            using (qs = Qubit[4]) 
            {
                let ans = Solve(qs);
                DumpRegister((), qs);
                ResetAll(qs);
            }
        }
    }
}