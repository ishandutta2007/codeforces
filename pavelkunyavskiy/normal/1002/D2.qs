namespace Solution
{
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Hello () : (Int[]) {
	    body {
                let n = 2;
                mutable res = new Int[n];

		using (qs = Qubit[n + 1]) {
                    Solve(qs, qs[0], res);
		}


                return res;
            }
	}
}

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            for (i in 0..Length(b)-1) {
               if (b[i] == 0) {
                  X(x[i]);
               }
               CNOT(x[i], y);
               if (b[i] == 0) {
                  X(x[i]);
               }
            }
        }
    }
}