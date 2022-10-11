namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit) : Int
    {
        body
        {
            H(qs);
            if (M(qs)==Zero)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[1])
            {
                if (index==1)
                {
                    H(register[0]);
                } else {
                    X(register[0]);
                    H(register[0]);
                }

                set dum = (index==Solve(register[0]));
                
                ResetAll(register);
            }
            return dum;
        }
    }
}