namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
   
    operation FUN (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            mutable b = new Int[Length(x)];
            for (k in 0..Length(x)-1)
            {
                set b[k] = k;
            }

            for (k in 0..Length(x)-1)
            {
                if (((b[k]%2)+2)%2==1)
                {
                    CNOT(x[k],y);
                }
                else
                {
                    X(x[k]);
                    CNOT(x[k],y);
                    X(x[k]);
                }
            }
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable ans = new Int[N];
            using (bits = Qubit[N+1])
            {
                Uf(bits[0..N-1],bits[N]);
                if (M(bits[N])==One)
                {
                    set ans[0]=1-(N%2);
                }
                else
                {
                    set ans[0]=N%2;
                }                

                ResetAll(bits);
            }
            return ans;
        }
    }



    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            mutable N = 8;
            
            mutable dumhet = Solve(N,FUN);
            
            for (ind in 0..N-1)
            {
                if (ind%2==dumhet[ind])
                {
                    set dum = dum + 1;
                }
            }
            return dum;
        }
    }
}