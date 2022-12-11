namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable ans = -1;
            using (qs = Qubit[1]) {
                H(qs[0]);
                if (M(qs[0]) == Zero) {
                    H(q);
                    if (M(q) == One) {
                        set ans = 0;
                    }
                } else {
                    if (M(q) == One) {
                        set ans = 1;
                    } 
                }
                ResetAll(qs);
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

    // operation Test () : Bool
    // {
    //     body 
    //     {   
    //         return Solve(q);
    //     }
    // }
}