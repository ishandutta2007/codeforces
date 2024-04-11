namespace qsharp
{
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Math;
        open Microsoft.Quantum.Diagnostics;

        operation A (q : Qubit) : Unit is Adj+Ctl { Y(q); }
        operation B (q : Qubit) : Unit is Adj+Ctl { Z(q); X(q); Rz(2.0 * PI(), q); }
        operation C (q : Qubit) : Unit is Adj+Ctl { Y(q); Rz(2.0 * PI(), q); }
        operation D (q : Qubit) : Unit is Adj+Ctl { Z(q); X(q); }

	operation Hello () : Unit
	{
           using (q = Qubit[6]) {
              Solution.Solve(q);
              DumpMachine();                 
           }
	}
}

namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Bitwise;

    operation Solve (input : Qubit[]) : Unit  {
       using (q = Qubit()) {
           repeat { 
             for (i in 0..Length(input)-1) { H(input[i]); } 
             Controlled X(input, q);
           } 
           until (M(q) == Zero)
           fixup { 
	      for (i in 0..Length(input)-1) { X(input[i]); }
              X(q);   
           } 
       }
    }
}