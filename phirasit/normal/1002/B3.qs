namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            ApplyToEach(H, qs);
            mutable ans = 0;
            if (M(qs[0]) == One) {
                set ans = ans + 2;
            }
            if (M(qs[1]) == One) {
                set ans = ans + 1;
            }
            return ans;
        }
    }

    operation Test () : () 
    {
        body 
        {
            using (qs = Qubit[2]) 
            {
                let ans = Solve(qs);
                DumpRegister((), qs);
                ResetAll(qs);
            }
        }
    }
}