namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    
    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            for (k in 0..Length(x)-1)
            {
                if (((b[k]%2)+2)%2==1)
                {
                    CNOT(x[k],y);
                }
                else
                {
                    X(x[k]);
                    CNOT(x[k],y);
                    X(x[k]);
                }
            }
        }
    }



    operation Solution2(index : Int) : Int { 
        body {
            mutable dum = 0;
            mutable dumhet = new Int[2];
            set dumhet[0]=13;
            set dumhet[0]=-1;
            using (register = Qubit[3])
            {
                Solve(register[0..1],register[2],dumhet);
                //{
                //    set dum = dum + 1;
                //}
                
                ResetAll(register);
            }
            using (register2 = Qubit[3])
            {
                H(register2[0]);
                Solve(register2[0..1],register2[2],dumhet);
                //{
                //    set dum = dum + 1;
                //}
                
                ResetAll(register2);
            }
            return dum;
        }
    }
}