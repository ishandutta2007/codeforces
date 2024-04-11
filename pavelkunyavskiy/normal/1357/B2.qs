namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Bitwise;

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
        using (q = Qubit[3]) {
           for (i in 0..2..Length(inputs)-1) { Controlled Inc([inputs[i]], q); }
           for (i in 1..2..Length(inputs)-1) { Controlled Dec([inputs[i]], q); }
           (ControlledOnInt(0, X))(q, output);
           (ControlledOnInt(3, X))(q, output);
           (ControlledOnInt(5, X))(q, output);
           for (i in 0..2..Length(inputs)-1) { Controlled Dec([inputs[i]], q); }
           for (i in 1..2..Length(inputs)-1) { Controlled Inc([inputs[i]], q); }
        }   
    }
}