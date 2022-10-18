namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs: Qubit[]) : Unit {
        let n = Length(qs);
        
        CNOT(qs[1],qs[2]);
        CNOT(qs[1],qs[0]);
        SWAP(qs[0],qs[1]);
        X(qs[1]);
        H(qs[0]);
        X(qs[2]);
        Controlled H([qs[2]],qs[1]);
        X(qs[2]);
        CNOT(qs[1],qs[2]);
    }

    operation Foo (n: Int) : Unit {
        using (qs = Qubit[3]) {
            for (iter in 0..99) {
                let res = Solve(qs);
                ResetAll(qs);
            }
        }
    }
}