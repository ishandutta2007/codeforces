namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[1]);
            CNOT(qs[0],qs[1]); 
            H(qs[0]);

            mutable x = 0;
            if (M(qs[0])==One)
            {
                set x = 1;
            }
            mutable y = 0;
            if (M(qs[1])==One)
            {
                set y = 1;
            }
            if (x==1 && y==1)
            {
                return 0;
            } elif (x==0 && y==1)
            {
                return 1;
            } elif (x==1 && y== 0)
            {
                return 2;
            }
            return 3;
        }
    }

    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            using (register = Qubit[2])
            {
                if (0==Solve(register))
                {
                    set dum = dum + 1;
                }
                
                ResetAll(register);
            }
            using (register2 = Qubit[2])
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