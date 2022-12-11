
namespace tmp
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation HelloQ () : Unit {
        let N = 4;

        // using (qs = Qubit[N]) {
        //     Solution.Prepare(qs);
            
        //     let omega = 2.09439510239; 
        //     Rz(omega, qs[1]);
        //     Rz(2.0*omega, qs[0]);
         
   
        //     // (Adjoint Solution.Prepare) (qs);
   
        //     DumpMachine($"output");
        //     ResetAll(qs);
        // }

        // let size = 1 <<< N;
        // using ((x, y) = (Qubit[N], Qubit())) {

        //     for (k in 0 .. N - 1) {
        //         H(x[k]);
        //     }

        //     Solution.Solve(x, y);

        //     DumpMachine($"output");

        //     ResetAll(x);
        //     Reset(y);

        // }
        
        // for unary operation
        Quantum.DumpUnitary.DumpUnitaryToFiles(N, Solution.Solve(_));
    }

    // operation TestRound(x : Int) : Int {
    //     mutable ans = 0;
    //     using (q = Qubit()) {

    //         let pi = 3.14159265359;
    //         let omega = 2.0/3.0 * pi;

    //         H(q);
    //         if (x == 1) {
    //             Rz(omega, q);
    //         } else { if (x == 2) {
    //             Rz(2.0 * omega, q);
    //         } }


    //         set ans = Solution.Solve(q);

    //         DumpMachine($"output_{x}");

    //         Reset(q);
    //     }
    //     return ans;
    // }
}

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

namespace Quantum.DumpUnitary
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = BoolArrFromPositiveInt(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine($"DU{k}");
                
                ResetAll(qs);
            }
        }
    }

    // The operation which is called from C# code
    operation CallDumpUnitary (N : Int) : Unit {
        // make sure the operation passed to DumpUnitaryToFiles matches the number of qubits set in Driver.cs
        let unitary = ApplyToEach(I, _);

        DumpUnitaryToFiles(N, unitary);
    }
}

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Increase(qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in N-1..-1..0) {
            Controlled X(qs[0..i-1], qs[i]);
        }
    }
    // operation Decrease(qs : Qubit[]) : Unit {
    //     body (...) {
    //         let N = Length(qs);
    //         for (i in N-1..-1..0) {
    //             for (j in 0..i-1) {
    //                 X(qs[j]);
    //             }
    //             for (j in )
    //             Controlled X(qs[0..i-1], qs[i]);
    //             for (j in 0..i-1) {
    //                 X(qs[j]);
    //             }
    //         }
    //     }
    //     controlled auto;
    // }
    // operation IsPos(qs : Qubit[], ans : Qubit) : Unit {
    //     body (...) {
    //         let N = Length(qs);
    //         for (i in 0..N-1) {
    //             X(qs[i]);
    //         }
    //         X(ans);
    //         Controlled X(qs, ans);
    //         for (i in 0..N-1) {
    //             X(qs[i]);
    //         }
    //     }
    //     adjoint auto;
    // }

    // operation GenerateTriangle(qs : Qubit[]) : Unit {
    //     let N = Length(qs);
    //     // let pi = 3.14159265359;
    //     if (N == 2) {
    //         // Controlled Rz([qs[0]], (pi, qs[1]));
    //         H(qs[0]);
    //         Controlled H([qs[0]], qs[1]);
    //         // H(qs[0]);
    //         // H(qs[1]);
    //     } else {
    //         GenerateTriangle(qs[0..N-2]);
    //     }

    // }

    operation Tri(qs : Qubit[]) : Unit {
        body (...) {
            let N = Length(qs);
            if (N == 2) {
                X(qs[0]);
                Controlled H([qs[1]], qs[0]);

                X(qs[0]);
                Controlled H([qs[0]], qs[1]);
                X(qs[0]);
                
                X(qs[1]);
                Controlled H([qs[1]], qs[0]);
                X(qs[1]);
            } else {
                let a = N-1;
                let b = N-2;
                Controlled Tri([qs[a]], qs[0..b]);
                X(qs[a]);
                for (i in 0..b) {
                    CNOT(qs[a], qs[i]);
                }
                X(qs[a]);

                for (i in 0..b) {
                    X(qs[i]);
                }
                Controlled H(qs[0..b], qs[a]);
                for (i in 0..b) {
                    X(qs[i]);
                }

                X(qs[a]);
                for (i in 0..b) {
                    CNOT(qs[a], qs[i]);
                }
                Controlled Tri([qs[a]], qs[0..b]);
                X(qs[a]);
            }
        }
        controlled auto;
    }
    operation Solve (qs : Qubit[]) : Unit {
        Tri(qs);
    }

    // operation Solve (q : Qubit) : Int {
    
    //     let pi = 3.  4159265359;
    //     // let omega = 2.09439510239;

    //     // Rz(-0.9736128512488899, q);
    //     // Ry(0.7854021398048143, q);
    //     // Rx(3.3953590908522924, q);
    //     // Rz(pi * 1.0/8.0, q);
    //     Rx(pi * 1.0/2.0, q);
    //     // Rx(pi * 1.0/13.0, q);
    //     // Rz(-pi * 5.0 / 6.0, q);
        
    //     // return 0;
    //     let ans = ResultAsInt([M(q)]);

    //     if (ans == 0) {
    //         return 2;
    //     } else {
    //         return 1;
    //     }
    // }
}