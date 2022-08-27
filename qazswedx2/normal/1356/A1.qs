namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (a=Qubit())
        {
            unitary(a);
            let q=M(a);
            if(q==Zero)
            {
                return 0;
            }
            else
            {
                X(a);
                return 1;
            }
        }
    }
}