namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable res = 0;
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            let ob1 = M(qs[0]);
            if(ob1 == One){
                set res = 1;
            }
            let ob2 = M(qs[1]);
            if(ob2 == One){
                set res = res + 2;
            }
            return res;
        }
    }
}