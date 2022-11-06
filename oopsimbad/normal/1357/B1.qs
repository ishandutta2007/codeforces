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
        if(Length(inputs)-i >= AbsI(Length(inputs)/2-c)) {
            if(i == Length(inputs)) {
                if(c == Length(inputs)/2) {
                    Controlled X(inputs, output);
                }
            } else {
                X(inputs[i]);
                Recur(inputs, output, i+1, c+1);
                X(inputs[i]);
                Recur(inputs, output, i+1, c);
            }
        }
    }
}