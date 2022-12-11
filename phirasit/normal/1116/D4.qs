
namespace tmp
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation HelloQ () : Unit {
        let N = 3;

        // using (x = Qubit[N]) {
        //     Solution.Solve(x);
        //     DumpMachine($"output");
        //     ResetAll(x);
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

        let N = Length(x);

        for (i in 0..N-2) {
            Controlled X([x[N-1]], x[i]);
        }
        H(x[N-1]);

        X(x[N-1]);
        for (i in 1..N-2) {
            X(x[i]);
        }
        for (i in N-2..-1..1) {
            ApplyToEach(X, x[1..i-1]);
            Controlled X(x[0..i-1], x[i]);
            ApplyToEach(X, x[1..i-1]);
        }
        X(x[N-1]);

        // for (i in N-2..-1..1) {
        //     Controlled X(x[0..i-1] + [x[N-1]], x[i]);
        // }
        for (i in 0..N-2) {
            Controlled X([x[N-1]], x[i]);
        }
    }
}