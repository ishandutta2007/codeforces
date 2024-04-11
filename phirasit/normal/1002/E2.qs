// namespace Solution {
//     open Microsoft.Quantum.Extensions.Diagnostics;
//     open Microsoft.Quantum.Primitive;
//     open Microsoft.Quantum.Canon;

//     operation Solve (q : Qubit) : Int
//     {
//         body
//         {
//             mutable ans = 0;
//             if (Random([0.7; 0.3]) == 0) {
//                 if (M(q) == One) {
//                     set ans = 1;
//                 } else {
//                     set ans = Random([0.8; 0.2]);
//                 }
//             } else {
//                 H(q);
//                 if (M(q) == Zero) {
//                     set ans = 1;
//                 }
//             }
//             return ans;
//         }
//     }

//     // operation Set (q: Qubit, r: Result) : ()
//     // {
//     //     body
//     //     {
//     //         if (M(q) != r) {
//     //             X(q);
//     //         }
//     //     }
//     // }

//     operation Test (x: Bool) : Int
//     {
//         body 
//         {   
//             mutable ans = 0;
//             using (qs = Qubit[1]) {
//                 let q = qs[0];
//                 if (x) {
//                     H(q);
//                 }
//                 set ans = Solve(q);
//                 Reset(q);
//             }
//             return ans;
//         }
//     }
// }
namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {

            mutable ans = new Int[N];
            for (i in 0..N-1) {
                set ans[i] = 0;
            }
            using (reg = Qubit[N+1]) {
                let xs = reg[0..N-1];
                let y = reg[N];
                
            //     ApplyToEach(Set(_, Zero), xs);
            //     Set(y, One);

            //     ApplyToEach(H, reg);

                // Uff(Uf, xs, y);
                Uf(xs, y);

                if ((M(y) == One) == (N % 2 == 1)) {
                    set ans[0] = 0;
                } else {
                    set ans[0] = 1;
                }
            //     DumpRegister((), reg);

            //     ApplyToEach(H, xs);
                
            //     for (i in 0 .. N-1) {
            //         if (M(xs[i]) == One) {
            //             set ans[i] = 1;
            //         } else {
            //             set ans[i] = 0;
            //         }
            //     }

                ResetAll(reg);
            }
            return ans;
        }
    }

    // operation Uff (Uf : ((Qubit[], Qubit) => ()), qs : Qubit[], p : Qubit) : ()
    // {
    //     body
    //     {
    //         Uf(qs, p);
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

    operation Test () : Int []
    {
        body 
        {   
            return Solve(4, XS);
        }
    }

    operation XS (xs: Qubit[], y: Qubit) : ()
    {
        body
        {
            for (i in 0 .. Length(xs)-1) {
                if (i < 3) {
                    CNOT(xs[i], y);
                } else {
                    X(xs[i]);
                    CNOT(xs[i], y);
                    X(xs[i]);
                }
            }
        }
    }
}