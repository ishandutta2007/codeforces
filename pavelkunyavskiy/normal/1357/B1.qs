namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;

    operation Inc (register : Qubit[]) : Unit is Adj+Ctl {
       for (i in Length(register)-1..-1..1) {
           Controlled X(register[0..i-1], register[i]);
       } 
       X(register[0]);
    }
    operation Dec (register : Qubit[]) : Unit is Adj+Ctl {
       for (i in 0..Length(register)-1) { X(register[i]); }
       Inc(register); 
       for (i in 0..Length(register)-1) { X(register[i]); }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
       let need = Length(inputs) / 2;
       using (qs = Qubit[4]) {
          for (i in 0..Length(inputs)-1) {
             Controlled Inc([inputs[i]], qs);
          }  
          (ControlledOnInt(need, X))(qs, output);
          for (i in 0..Length(inputs)-1) {
             Controlled Dec([inputs[i]], qs);
          }  
       }
    }
}