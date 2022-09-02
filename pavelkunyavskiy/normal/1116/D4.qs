namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
        open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : Unit {
         for (i in 0..Length(qs)-2) {
            CNOT(qs[Length(qs)-1], qs[i]);
         }
         X(qs[0]);
         for (i in 1..Length(qs)-2) {
            (ControlledOnInt(0, X))(qs[0..i-1], qs[i]);
         }
         for (i in 0..Length(qs)-2) {
             X(qs[i]);
         }
         H(qs[Length(qs)-1]);
         for (i in 0..Length(qs)-2) {
             CNOT(qs[Length(qs)-1], qs[i]);
         }
    }

}