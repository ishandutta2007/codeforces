namespace qsharp
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Testing;
    open Microsoft.Quantum.Extensions.Diagnostics;

    function pattern(i : Int, j : Int) : Bool {
        if (i == 0 || i == 1 || i == 6 || i == 7) {
            return j == 0 || j == 1 || j == 6 || j == 7; 
        }
        if (i == 2 || i == 3) {
            return j == 3 || j == 4;
        } 
        if (i == 4 || i == 5) {
            return j == 2 || j == 5;
        } 
        return true; 
    } 

    operation Hello () : Unit
    {
        body (...) {
            Message("Hello, World!");
                    using (qs = Qubit[3]) { 
                         for (i in 0..7) { 
                            let binary = BoolArrFromPositiveInt(i, 3);
                            ApplyPauliFromBitString(PauliX, true, binary, qs);
                            Solution.Solve(qs);
                            DumpMachine();
                            for (j in 0..7) {                    
                                let nonZero = pattern(j, i);
                                Message($"Check {i}, {j}, expected {nonZero}");
                    
                                if (nonZero) {                        
                                   AssertProbInt(j, 0.5 + 0.0001, LittleEndian(qs), 0.5);
                                } else {                        
                                   AssertProbInt(j, 0.0, LittleEndian(qs), 0.0001);
                                }
                            }
                            ResetAll(qs);                         
                         }
                    }
        }
    }
}
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve2 (qs : Qubit[]) : Unit {
           body (...) {
           (Controlled H)([qs[1], qs[2]], qs[0]);
           X(qs[1]); X(qs[2]); 
           (Controlled H)([qs[1], qs[2]], qs[0]);
           X(qs[1]); X(qs[2]); 

           CNOT(qs[1], qs[2]);
           X(qs[2]);
           (Controlled H)([qs[2]], qs[1]);
           X(qs[2]);
           CNOT(qs[1], qs[2]);


           (Controlled H)([qs[1]], qs[0]);
           (Controlled H)([qs[2]], qs[0]);
           (Controlled X)([qs[2]], qs[1]);
           (Controlled X)([qs[1]], qs[2]);
           (Controlled X)([qs[2]], qs[1]);
           (Controlled X)([qs[2], qs[0]], qs[1]);
           (Controlled X)([qs[1], qs[0]], qs[2]);
           (Controlled X)([qs[2], qs[0]], qs[1]);
           }

           adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
           (Adjoint Solve2)(qs);
    }
}