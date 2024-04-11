namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let x = M(q);
            if (x == Zero) {
                return 1;
            }
            return -1;
        }
    }
}