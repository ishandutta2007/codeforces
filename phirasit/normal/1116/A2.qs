
namespace tmp
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation HelloQ () : Unit {
        let N = 2;

        using (x = Qubit[N]) {
            // Solution.Solve(x, [
            //     [false, true, true, false, false], 
            //     [true, false, true, false, true], 
            //     [true, true, false, true, true], 
            //     [true, true, true, false, false]]);
            // Solution.Solve(x, [
            //     [false, true, true], 
            //     [true, false, true], 
            //     [true, true, false], 
            //     [true, true, true]]);
            Solution.Solve(x, [[false, false], [true, true], [false, true], [true, false]]);
            DumpMachine($"output");
            ResetAll(x);
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

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {

        mutable idx = -1;
        mutable founda = false;
        mutable foundb = false;
        let N = Length(qs);
    

        // create the first two states
        for (i in 0 ..N-1) {
            if (bits[0][i] != bits[1][i]) {
                set founda = false;
                set foundb = false;
                mutable ta = 0;
                if (bits[2][i] == bits[0][i]) {
                    set ta = 0;
                } else {
                    set ta = 1;
                }
                let tb = 1 - ta;
                for (j in 0..N-1) {
                    if (bits[ta][j] != bits[2][j] && j != i) {
                        set founda = true;
                    }
                    if (bits[tb][j] != bits[3][j] && j != i) {
                        set foundb = true;
                    }
                }
                if (founda && foundb) {
                    set idx = i;
                }
            }
        }

        H(qs[idx]);
        for (i in 0..N-1) {
            if (i != idx) {
                if (bits[0][i] != bits[1][i]) {
                    CNOT(qs[idx], qs[i]);
                    if (bits[0][i] != bits[0][idx]) {
                        X(qs[i]);
                    }
                } else { if (bits[0][i] == true) {
                    X(qs[i]);
                }}
            }
        }

        mutable idx2 = 0;

        // create state 2                
        mutable a = 0;
        if (bits[2][idx] == bits[0][idx]) {
            set a = 0;
        } else {
            set a = 1;
        }
        let b = 1 - a;

        for (i in 0..N-1) {
            if (bits[a][i] != bits[2][i] && i != idx) {
                set idx2 = i;
            }
        }

        if (bits[a][idx] == false) { X(qs[idx]); }
        if (bits[a][idx2] == true) { CNOT(qs[idx], qs[idx2]); }
        Controlled H([qs[idx]], qs[idx2]);

        if (bits[a][idx2] == true) { CNOT(qs[idx], qs[idx2]); }
        for (i in 0..N-1) {
            if (i != idx && i != idx2) {
                if (bits[a][i] != bits[2][i]) {
                    Controlled X([qs[idx], qs[idx2]], qs[i]);
                }
            }
        }
        if (bits[a][idx2] == true) { CNOT(qs[idx], qs[idx2]); }
        if (bits[a][idx] == false) { X(qs[idx]); }
        
        // create state 3
        for (i in 0..N-1) {
            if (bits[b][i] != bits[3][i] && i != idx) {
                set idx2 = i;
            }
        }

        if (bits[b][idx] == false) { X(qs[idx]); }
        if (bits[b][idx2] == true) { CNOT(qs[idx], qs[idx2]); }
        Controlled H([qs[idx]], qs[idx2]);

        if (bits[b][idx2] == true) { CNOT(qs[idx], qs[idx2]); }
        for (i in 0..N-1) {
            if (i != idx && i != idx2) {
                if (bits[b][i] != bits[3][i]) {
                    Controlled X([qs[idx], qs[idx2]], qs[i]);
                }
            }
        }
        if (bits[b][idx2] == true) { CNOT(qs[idx], qs[idx2]); }

        if (bits[b][idx] == false) { X(qs[idx]); }
        if (bits[b][idx] != bits[3][idx]) {
            for (i in 0..N-1) {
                if (i != idx && bits[3][i] == false) {
                    X(qs[i]);
                }
            }
            Controlled X(qs[0..idx-1] + qs[idx+1..N-1], qs[idx]);
            for (i in 0..N-1) {
                if (i != idx && bits[3][i] == false) {
                    X(qs[i]);
                }
            }
        }
    }
}