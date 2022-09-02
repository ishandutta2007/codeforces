namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Bitwise;

    operation Solve (input : Qubit[], parity: Int) : Unit  {
       for (i in 1..Length(input)-1) { 
          H(input[i]); 
          CNOT(input[i], input[0]); 
       } 
       if (parity == 1) {X(input[0]);}
    }
}