namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            Z(qs[0]);
            X(qs[0]);
            (Controlled Z)(qs[0..0], qs[1]);
            X(qs[0]);
            
            H(qs[0]);
            H(qs[1]);
            
            mutable ans = 0;
            if (M(qs[1]) == One) {
                set ans = ans + 2;
            }
            if (M(qs[0]) == One) {
                set ans = ans + 1;
            }

            return ans;
        }
    }
    // operation Solve (q : Qubit) : Int
    // {
    //     body
    //     {
    //         mutable ans = 0;
            
    //         if (M(q) == One) {
    //             set ans = 1;
    //         }
    //         return ans;
    //     }
    // }

    // operation Set (q: Qubit, r: Result) : ()
    // {
    //     body
    //     {
    //         if (M(q) != r) {
    //             X(q);
    //         }
    //     }
    // }

    operation Test(x: Int) : Int
    {
        body 
        {   
            mutable ans = 0;
            using (qs = Qubit[2]) {
                let q0 = qs[0];
                let q1 = qs[1];
                H(q0);
                H(q1);
                Z(qs[1]);
                X(qs[1]);
                (Controlled Z)(qs[0..0], qs[1]);
                X(qs[1]);

                if (x == 1) {
                    X(qs[1]);
                    Z(qs[1]);
                    X(qs[1]);
                }

                if (x == 2) {
                    X(qs[0]);
                    Z(qs[0]);
                    X(qs[0]);
                }

                if (x == 3) {
                    X(qs[0]);
                    X(qs[1]);
                }

                DumpRegister((), qs);
                set ans = Solve(qs);
                ResetAll(qs);
            }
            return ans;
        }

    }
    // operation Test (x: Bool) : Int
    // {
    //     body 
    //     {   
    //         mutable ans = 0;
    //         using (qs = Qubit[1]) {
    //             let q = qs[0];
    //             if (x) {
    //                 H(q);
    //             }
    //             set ans = Solve(q);
    //             Reset(q);
    //         }
    //         return ans;
    //     }
    // }
}