namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable dum = true;
            for (i in 0..Length(bits0)-1)
            {
                mutable dumhet = One;
                if (bits0[i])
                {
                    set dumhet = Zero;
                }

                if (M(qs[i])==dumhet)
                {
                    set dum = false;
                }
            }
            if (dum)
            {
                return 0;
            } else
            {
                return 1;
            }
        }
    }

    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            using (register = Qubit[index])
            {
                mutable bits0 = new Bool[index];
                mutable bits1 = new Bool[index];
                
                set bits0[0] = true;
                
                X(register[0]);
                set dum = Solve(register,bits0,bits1);
                
                ResetAll(register);
            }
            return dum;
        }
    }
}