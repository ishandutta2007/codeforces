namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Shares (q0 : Qubit, q1 : Qubit) : ()
    {
        body
        {
            (Controlled H)([q0],q1);
            CNOT(q1,q0);
        }
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            X(qs[0]);
            mutable depth = 1;
            repeat
            {
            } until (depth>=Length(qs))
            fixup 
            { 
                for (ind in 0..depth-1)
                {
                    Shares(qs[ind],qs[ind+depth]);
                }
                set depth = depth*2; 
            }
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = 0;
            using (register = Qubit[8])
            {
                Solve(register);
                
                for (ind in 1..Length(register)-1)
                {
                    if (M(register[ind])==One)
                     {
                        set dum = dum + 1;
                     }
                }
                ResetAll(register);
            }
            return dum==1;
        }
    }
}