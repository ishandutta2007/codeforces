namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable ans = 0;
            Ry(0.39269908, q);
            if (M(q) == One) {
                set ans = 1;
            }
            return ans;
        }
    }

    // operation Set (q: Qubit, r: Result) : ()
    // {
    //     body
    //     {
    //         if (M(q) != r) {
    //             X(q);
    //         }
    //     }
    // }

    operation Test (x: Bool) : Int
    {
        body 
        {   
            mutable ans = 0;
            using (qs = Qubit[1]) {
                let q = qs[0];
                if (x) {
                    H(q);
                }
                set ans = Solve(q);
                Reset(q);
            }
            return ans;
        }
    }
}