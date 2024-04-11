namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        Recur(inputs, output, 0, 0);
    }
    operation Recur(inputs : Qubit[], output: Qubit, i : Int, c : Int) : Unit is Adj+Ctl {
        if(i == Length(inputs)) {
            if(c%3 == 0) {
                Controlled X(inputs, output);
            }
        } else {
            X(inputs[Length(inputs)-i-1]);
            Recur(inputs, output, i+1, c*2);
            X(inputs[Length(inputs)-i-1]);
            Recur(inputs, output, i+1, c*2+1);
        }
    }
}