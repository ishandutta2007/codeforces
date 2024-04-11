
namespace tmp
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation HelloQ () : Unit {
        let N = 2;

        using (x = Qubit[N]) {
            Solution.Solve(x);
            DumpMachine($"output");
            ResetAll(x);
        }

        // let size = 1 <<< N;
        // using ((x, y) = (Qubit[N], Qubit())) {

            // for (k in 0 .. N - 1) {
            //     H(x[k]);
            // }

            // Solution.Solve(x, y);

            // DumpMachine($"output");

            // ResetAll(x);
            // Reset(y);

        // }
        
        // for unary operation
        // Quantum.DumpUnitary.DumpUnitaryToFiles(N, Solution.Solve(_));
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

    operation Solve (x : Qubit[]) : Unit {
        // body (...) {
        PrepareUniformSuperposition(3, BigEndian(x));
        // }
        // adjoint auto;
    }
}