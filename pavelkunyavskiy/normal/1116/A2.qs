namespace qsharp
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
        open Microsoft.Quantum.Extensions.Diagnostics;

    operation Hello () : Unit
    {
        body (...) {
            Message("Hello, World!");
                    using (q = Qubit[2]) {
                             let x = [[true, true], [true, false], [false, true], [false, false]];
                             Solution.Solve(q, x); 
                             DumpMachine();
                             ResetAll(q);                     
                    }
        }
    }
}
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        using (a = Qubit[2]) {
            H(a[0]); H(a[1]);
            for (i in 0..3) {
                for (j in 0..1) {
                    if (i / (j + 1) % 2 == 0) { 
                        X(a[j]); 
                    }
                }
                for (j in 0..Length(qs)-1) {
                    if (bits[i][j]) {
                       (Controlled X)(a, qs[j]);  
                    }
                } 
                for (j in 0..1) {
                    if (i / (j + 1) % 2 == 0) { 
                        X(a[j]); 
                    }
                }
            }

            for (i in 0..3) {
                if (i == 1 || i == 3) { (ControlledOnBitString(bits[i], X))(qs, a[0]); }
                if (i == 2 || i == 3) { (ControlledOnBitString(bits[i], X))(qs, a[1]); }
            }
        }
    }
}