namespace Solution {
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable ans = new Int[N];
            using (reg = Qubit[N+1]) {
                let xs = reg[0..N-1];
                let y = reg[N];
                
                ApplyToEach(Set(_, Zero), xs);
                Set(y, One);

                ApplyToEach(H, reg);

                Uf(xs, y);
    
                ApplyToEach(H, xs);
                
                for (i in 0 .. N-1) {
                    if (M(xs[i]) == One) {
                        set ans[i] = 1;
                    } else {
                        set ans[i] = 0;
                    }
                }

                ResetAll(reg);
            }
            return ans;
        }
    }
    operation Set (q: Qubit, r: Result) : ()
    {
        body
        {
            if (M(q) != r) {
                X(q);
            }
        }
    }

    operation Test () : Int []
    {
        body 
        {   
            return Solve(4, XS);
        }
    }

    operation XS (xs: Qubit[], y: Qubit) : ()
    {
        body
        {
            for (i in 0 .. Length(xs)-1) {
                CNOT(xs[i], y);
            }
        }
    }
}