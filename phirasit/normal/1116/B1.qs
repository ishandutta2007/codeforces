
namespace tmp
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation HelloQ () : Unit {
        let N = 3;

        using (qs = Qubit[N]) {
            Solution.Prepare(qs);
            
            let omega = 2.09439510239; 
            Rz(omega, qs[1]);
            Rz(2.0*omega, qs[0]);
         
   
            // (Adjoint Solution.Prepare) (qs);
   
            DumpMachine($"output");
            ResetAll(qs);
        }

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
        // Quantum.DumpUnitary.DumpUnitaryToFiles(N, Solution.Solve(_));
    }

    operation TestRound(x : Int) : Int {
        mutable ans = 0;
        using (qs = Qubit[3]) {
        // using (q = Qubit()) {
            // PrepareUniformSuperposition(3, BigEndian(qs));
            Solution.Prepare(qs);

            let omega = 2.09439510239; 
            let pi = 3.14159265359;
            if (x == 0) {
                Rz(omega, qs[1]);
                Rz(2.0*omega, qs[2]);
            } else {
                Rz(2.0*omega, qs[1]);
                Rz(omega, qs[2]);
            }
            
            // Rz(2.0*pi, qs[0]);
            // Rz(2.0*pi, qs[1]);
            // Rz(2.0*pi, qs[2]);

            // H(q);
            // if (x == 1) {
            //     Rz(omega, q);
            // } else { if (x == 2) {
            //     Rz(2.0 * omega, q);
            // } }

            set ans = Solution.Solve(qs);

            DumpMachine($"output");

            ResetAll(qs);
        }
        return ans;
    }
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

    // operation Increase(qs : Qubit[]) : Unit {
    //     let N = Length(qs);
    //     for (i in N-1..-1..0) {
    //         Controlled X(qs[0..i-1], qs[i]);
    //     }
    // }
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

    // operation Solve (qs : Qubit[]) : Unit {
    //     let N = Length(qs);
    //     Increase(qs);
    //     for (i in 0..10) {
    //         using (x = Qubit()) {
    //             H(x);
    //             Controlled Decrease([x], qs);
    //             Reset(x);
    //         }
    //     }
    // }

    operation Prepare (qs : Qubit[]) : Unit {
        body (...) {
            Ry(1.2309594173407747, qs[0]);
            SWAP(qs[0], qs[1]);

            X(qs[1]);
            Controlled H([qs[1]], qs[0]);
            X(qs[1]);
            SWAP(qs[0], qs[2]);

            X(qs[1]);
            X(qs[2]);
            Controlled X(qs[1..2], qs[0]);
            X(qs[1]);
            X(qs[2]);
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Int {
    
        
    //     let pi = 3.14159265359;
    //     let omega = 2.09439510239;

    //     let m = Random([1.0/3.0,1.0/3.0,1.0/3.0]);
    //     let k = Random([1.0/2.0,1.0/2.0]);

    //     if (m == 0) {
    //         Rz(pi, q);
    //     } else { if (m == 1) {
    //         Rz(pi -omega, q);
    //     } else { if (m == 2) {
    //         Rz(pi -omega * 2.0, q);
    //     } } }

    //     H(q);

    //     let ans = ResultAsInt([M(q)]);
    //     if (ans == 0) {
    //         return m;
    //     } else {
    //         return (m+1) % 3;
    //     }

        let pi = 3.14159265359;
        let omega = 2.0 / 3.0 * pi; 

        Rz(2.0 * omega, qs[1]);
        Rz(omega, qs[2]);

        (Adjoint Prepare) (qs);

        if (ResultAsInt([M(qs[0]), M(qs[1]), M(qs[2])]) == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}