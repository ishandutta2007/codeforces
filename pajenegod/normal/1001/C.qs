namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let N = Length(qs);
            H(qs[0]);
            for (i in 1..N-1)
            {
                CNOT(qs[0],qs[i]);
            }
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[index+1])
            {
                
                Solve(register);
                
                set dum = true; 
                ResetAll(register);
            }
            return dum;
        }
    }
}