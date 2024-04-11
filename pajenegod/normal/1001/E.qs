namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Crap (qs : Qubit[], index : Int) : ()
    {
        body
        {
            // your code here
            if (index == 0)
            {
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            } elif (index == 1)
            {
                X(qs[0]);
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            } elif (index == 2)
            {
                X(qs[1]);
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            } else 
            {
                X(qs[0]);
                X(qs[1]);
                H(qs[0]);
                CNOT(qs[0],qs[1]);

            }
        }
    }
    
    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            if (M(qs[0])==Zero && M(qs[1])==Zero)
            {
                return 0;
            } elif (M(qs[0])==One && M(qs[1])==One)
            {
                return 3;
            } elif (M(qs[0])==One)
            {
                return 1;
            } else
            {
                return 2;
            }
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[2])
            {
                Crap(register, index);
                set dum = index==Solve(register);
                
                ResetAll(register);
            }
            return dum;
        }
    }
}