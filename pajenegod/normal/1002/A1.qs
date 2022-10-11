namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            for (ind in 0..Length(qs)-1)
            {
                H(qs[ind]);
            }
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[2])
            {
                
                Solve(register);
                
                set dum = true; 
                ResetAll(register);
            }
            return dum;
        }
    }
}