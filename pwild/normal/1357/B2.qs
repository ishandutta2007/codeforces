namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Incr (counter : Qubit[]) : Unit is Adj+Ctl {
        if (Length(counter) > 1) {
            (Controlled Incr)([counter[0]], counter[1...]);
        }
        X(counter[0]);
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (counter = Qubit[4]) {
            within {
                for (i in 0 .. Length(inputs)-1) {
                    if (i%2 == 0) {
                        (Controlled Incr)([inputs[i]], counter);
                    } else {
                        (Controlled (Adjoint Incr))([inputs[i]], counter);    
                    }
                }
            } apply {
                (ControlledOnInt(0, X))(counter, output);
                (ControlledOnInt(3, X))(counter, output);
                (ControlledOnInt(13, X))(counter, output); // -3
            }
        }
    }
}