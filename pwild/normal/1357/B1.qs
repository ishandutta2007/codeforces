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
                for (q in inputs) {
                    (Controlled Incr)([q], counter);
                }
            } apply {
                (ControlledOnInt(Length(inputs)/2, X))(counter, output);
            }
        }
    }
}