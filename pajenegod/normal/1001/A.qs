namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(q : Qubit, sign : Int) : ()
    {
        body
        {
            if (sign == -1)
            {
                X(q);
            }
            H(q);
        }
    }

    operation Solution2(sign : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[1])
            {
                let msg = register[0];
                
                Solve(msg, sign);
                
                H(msg);
                if (sign == -1)
                {
                    X(msg);
                }
                set dum = M(msg)==Zero; 
                ResetAll(register);
            }
            return dum;
        }
    }
}