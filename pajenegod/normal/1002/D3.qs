namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    
    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            (Controlled X)(x,y);
            
            X(x[0]);
            (Controlled X)(x,y);
            X(x[0]);
            
            X(x[1]);
            (Controlled X)(x,y);
            X(x[1]);
            
            X(x[2]);
            (Controlled X)(x,y);
            X(x[2]);
        }
    }



    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            using (register = Qubit[4])
            {
                Solve(register[0..2],register[3]);
                //{
                //    set dum = dum + 1;
                //}
                
                ResetAll(register);
            }
            using (register2 = Qubit[4])
            {
                H(register2[0]);
                Solve(register2[0..2],register2[3]);
                //{
                //    set dum = dum + 1;
                //}
                
                ResetAll(register2);
            }
            return dum;
        }
    }
}