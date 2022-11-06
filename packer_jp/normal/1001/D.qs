namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let res = M(q);
            if(res == Zero){
                return 1;
            }else{
                return -1;
            }
        }
    }
}