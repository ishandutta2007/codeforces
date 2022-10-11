namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[], index : Int) : ()
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

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[2])
            {
                
                Solve(register, index);
                
                set dum = true; 
                ResetAll(register);
            }
            return dum;
        }
    }
}