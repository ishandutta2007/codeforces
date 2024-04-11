namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : (Int)
    {
        body
        {
            RFrac(PauliY,-1, 3, q);
            if (M(q) == One) {
                return 1;
            } 
            return 0;
        }
    }
}