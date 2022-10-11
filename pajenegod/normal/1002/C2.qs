namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable dum = 0;
            using (reg = Qubit[1])
            {
                H(reg[0]);
                if (M(reg[0])==Zero)
                {
                    set dum = 1;
                }
                ResetAll(reg);
            }
            
            if (dum==0)
            {
                H(q);
                if (M(q)==One)
                {
                    return 0;
                }
            } 
            else 
            {
                if (M(q)==One)
                {
                    return 1;
                }

            }
            return -1;
        }
    }

    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            using (register = Qubit[1])
            {
                if (0==Solve(register[0]))
                {
                    set dum = dum + 1;
                }
                
                ResetAll(register);
            }
            using (register2 = Qubit[1])
            {
                H(register2[0]);
                if (1==Solve(register2[0]))
                {
                    set dum = dum + 1;
                }
                
                ResetAll(register2);
            }
            return dum;
        }
    }
}