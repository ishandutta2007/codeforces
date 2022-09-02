namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        for (i in 0..Length(qs)-2) {
           let j = Length(qs) - i - 1;
           for (k in 0..j-1) {
              Controlled H(qs[j..Length(qs)-1], qs[k]);
           }
           X(qs[j]);
        }
        for (i in 0..Length(qs)-2) {
           let j = Length(qs) - i - 1;
           X(qs[j]);
        }
    }
}