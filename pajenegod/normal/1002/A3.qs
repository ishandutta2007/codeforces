namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve2 (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable first = -1;
            for (ind in 0..Length(bits)-1)
            {
                if (bits[ind] && first==-1)
                {
                    set first = ind;
                }
            }
            if (first==-1)
            {
                return ();
            }
            H(qs[first]);
            for (ind in first+1..Length(bits)-1)
            {
                if (bits[ind])
                {
                    CNOT(qs[first],qs[ind]);
                }
            }

        }
    }

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable bits = new Bool[Length(bits0)];
            for (ind in 0..Length(bits0)-1)
            {
                set bits[ind] = (bits0[ind]!=bits1[ind]);
            }
            Solve2(qs,bits);
            for (ind in 0..Length(bits0)-1)
            {
                if (bits0[ind])
                {
                    X(qs[ind]);
                }
            }

        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[2])
            {
                mutable ar = new Bool[2];
                set ar[0] = false;
                set ar[1] = true;
                mutable ar2 = new Bool[2];
                set ar2[0] = true;
                set ar2[1] = true;
                Solve(register,ar,ar2);
                
                set dum = true; 
                ResetAll(register);
            }
            return dum;
        }
    }
}