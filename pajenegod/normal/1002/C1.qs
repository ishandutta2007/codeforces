namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(3.926,q);
            if (M(q)==Zero)
            {
                return 1;
            } else 
            {
                return 0;
            }
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = true;
            using (register = Qubit[1])
            {
                set dum = dum && (0==Solve(register[0]));
                
                ResetAll(register);
            }
            using (register2 = Qubit[1])
            {
                H(register2[0]);
                set dum = dum && (1==Solve(register2[0]));
                
                ResetAll(register2);
            }
            return dum;
        }
    }
}