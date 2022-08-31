namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (a=Qubit[2])
        {
            unitary(a);
            let q=M(a[1]);
            if(q==Zero)
            {
                return 1;
            }
            else
            {
                X(a[1]);
                return 0;
            }
        }
    }
}