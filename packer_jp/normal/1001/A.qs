namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            if(sign == -1){
                X(q);
            }
            H(q);
        }
    }
}