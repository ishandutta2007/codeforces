namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            let a = M(qs[0]);
            let b = M(qs[1]);
            if (a == Zero && b == Zero) {
                return 0;
            }
            if (a == One && b == Zero) {
                return 1;
            }
            if (a == Zero && b == One) {
                return 2;
            }
            if (a == One && b == One) {
                return 3;
            }
            return 0;
        }
    }
}