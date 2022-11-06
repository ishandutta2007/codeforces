namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (x : Qubit[], y : Qubit) : () {
        body {
            CCNOT(x[0],x[1],y);
            CCNOT(x[0],x[2],y);
            CCNOT(x[1],x[2],y);
        }
    }

}