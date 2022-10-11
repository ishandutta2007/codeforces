namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    
    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable ans = new Int[N];
            using (bits = Qubit[N+1])
            {
                for (ind in 0..N-1)
                {
                    H(bits[ind]);
                }
                X(bits[N]);
                H(bits[N]);
                Uf(bits[0..N-1],bits[N]);
                for (ind in 0..N-1)
                {
                    H(bits[ind]);
                }

                for (ind in 0..N-1)
                {
                    if (M(bits[ind])==Zero)
                    {
                        set ans[ind]=0;
                    } 
                    else
                    {
                        set ans[ind]=1;
                    }
                }


                ResetAll(bits);
            }
            return ans;
        }
    }



    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            using (register = Qubit[4])
            {
                //Solve(register[0..2],register[3]);
                //{
                //    set dum = dum + 1;
                //}
                
                ResetAll(register);
            }
            using (register2 = Qubit[4])
            {
                H(register2[0]);
                //Solve(register2[0..2],register2[3]);
                //{
                //    set dum = dum + 1;
                //}
                
                ResetAll(register2);
            }
            return dum;
        }
    }
}