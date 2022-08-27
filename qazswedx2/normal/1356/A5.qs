namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (a=Qubit[1])
        {
            using (b=Qubit())
            {
                H(a[0]);
                Controlled unitary(a,b);
                H(a[0]);
                let q=M(a[0]);
                if(q==Zero)
                {
                    return 0;
                }
                else
                {
                    X(a[0]);
                    return 1;
                }
            }
        }
    }
}