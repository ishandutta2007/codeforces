namespace Solution
{
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Hello () : (Int[]) {
	    body {
                let n = 4;
                mutable res = new Int[n];

		using (qs = Qubit[n]) {
                    H(qs[0]); H(qs[1]);
                    set res[0] = Solve(qs);
		    ResetAll(qs);

                    X(qs[0]); H(qs[0]); H(qs[1]);
                    set res[1] = Solve(qs);
		    ResetAll(qs);

                    X(qs[1]); H(qs[0]); H(qs[1]);
                    set res[2] = Solve(qs);
		    ResetAll(qs);

                    X(qs[0]); X(qs[1]); H(qs[0]); H(qs[1]);
                    set res[3] = Solve(qs);
		    ResetAll(qs);

		}


                return res;
            }
	}
}

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : (Int)
    {
        body
        {
            (Controlled Z)([qs[0]], qs[1]);
            H(qs[0]);
            H(qs[1]);
            mutable res = 0;
            if (M(qs[0]) == One) {
                set res = res + 1;
            } 
            if (M(qs[1]) == One) {
                set res = res + 2;
            } 
            return 3 - res;
        }
    }
}