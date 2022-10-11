namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable is_const = true;
            using (register = Qubit[N+1])
            {
                for (ind in 0..N-1)
                {
                    H(register[ind]);
                }
                X(register[N]);
                H(register[N]);
                Uf(register[0..N-1],register[N]);
                for (ind in 0..N-1)
                {
                    H(register[ind]);
                }
                
                for (ind in 0..N-1)
                {
                    if (M(register[ind])==One)
                    {
                        set is_const = false;
                    }
                }
                ResetAll(register);
            }
            return is_const;
        }
    }

    operation Solve2 (x : Qubit[], y : Qubit, k : Int) : ()
    {
        body
        {
            CNOT(x[k],y);
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[index+1])
            {   
                X(register[0]);
                Solve2(register[0..index-1],register[index],0);
                
                set dum = M(register[index])==One; 
                ResetAll(register);
            }
            return dum;
        }
    }
}