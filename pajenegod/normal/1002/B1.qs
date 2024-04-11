namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable banan = 0;
            for (ind in 0..Length(qs)-1)
            {
                if (M(qs[ind])==One)
                {
                    set banan = banan + 1;
                }
            }
            return banan;
        }
    }

    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            using (register = Qubit[1])
            {
                if (0==Solve(register))
                {
                    set dum = dum + 1;
                }
                
                ResetAll(register);
            }
            using (register2 = Qubit[1])
            {
                H(register2[0]);
                if (1==Solve(register2))
                {
                    set dum = dum + 1;
                }
                
                ResetAll(register2);
            }
            return dum;
        }
    }
}