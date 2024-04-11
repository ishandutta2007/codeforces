namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(1.9106332362490184, qs[0]);
        (Controlled H)([qs[0]], qs[1]);
        CNOT(qs[1], qs[0]);
    }

}