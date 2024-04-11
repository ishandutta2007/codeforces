namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable result = false;

            using (xs = Qubit[N]) {

                using (ys = Qubit[1]) {

                    for (i in 0 .. Length(xs) - 1) {
                        Set(Zero, xs[i]);
                    }
                    Set(One, ys[0]);

                    ApplyToEach(H, xs);
                    H(ys[0]);

                    Uf(xs, ys[0]);

                    ApplyToEach(H, xs);

                    set result = true;
                    for (i in 0 .. Length(xs) - 1) {
                        if (M(xs[i]) == One) {
                            set result = false;
                        }
                        Set(Zero, xs[i]);
                    }
                    Set(Zero, ys[0]);
                }
            }
            return result;
        }
    }

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Balance (xs : Qubit[], y : Qubit) : ()
    {
        body
        {
            // for (i in 0 .. Length(xs) - 1) {
            //     CNOT(xs[i], y);
            // }
            CNOT(xs[0], y);
        }
    }

    operation Constant (xs : Qubit[], y : Qubit) : ()
    {
        body
        {
            Set(One, y);
        }
    }

    operation SolveBalance (n : Int) : Bool
    {
        body
        {
            return Solve(n, Balance(_, _));
        }
    }

    operation SolveConstant (n : Int) : Bool
    {
        body
        {
            return Solve(n, Constant(_, _));
        }
    }
}