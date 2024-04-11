namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;
    
    operation XWing (qs: Qubit[]) : Unit {
        let n = Length(qs);

        X(qs[0]);
        H(qs[0]);
        for (i in 1..n-1) { CNOT(qs[0],qs[i]); }
        H(qs[0]);
        for (i in 1..n-1) { CNOT(qs[0],qs[i]); }
        H(qs[0]);
    }

    operation CyclicShift (qs: Qubit[]) : Unit {
        body(...) {
            let n = Length(qs);
            for (i in n-1..-1..1) {
                Controlled X(qs[0..i-1],qs[i]);
            }
            X(qs[0]);
        }
        adjoint auto;
        controlled auto;
        adjoint controlled auto;
    }

    operation Solve (qs: Qubit[]) : Unit {
        let n = Length(qs);
        
        XWing(qs);

        Controlled (Adjoint CyclicShift)([qs[n-1]],qs[0..n-2]);
        X(qs[n-1]);
        Controlled (CyclicShift)([qs[n-1]],qs[0..n-2]);

    }
}