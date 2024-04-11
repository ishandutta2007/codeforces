namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;  
    open Microsoft.Quantum.Diagnostics;

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(inputs);

        using (qs = Qubit[4]) {
            for (i in 0..n-1) {
                for (t in 0..i%2) {
                    CNOT(inputs[i], qs[0]);
                    (ControlledOnBitString([true, false], X))([inputs[i], qs[0]], qs[1]);
                    (ControlledOnBitString([true, false, false], X))([inputs[i], qs[0], qs[1]], qs[2]);
                    (ControlledOnBitString([true, false, false, false], X))([inputs[i], qs[0], qs[1], qs[2]], qs[3]);
                }
			}

            (ControlledOnBitString([false, false, false, false], X))(qs, output);
            (ControlledOnBitString([true, true, false, false], X))(qs, output);
            (ControlledOnBitString([false, true, true, false], X))(qs, output);
            (ControlledOnBitString([true, false, false, true], X))(qs, output);
            (ControlledOnBitString([false, false, true, true], X))(qs, output);

            for (i in 0..n-1) {
                for (t in 0..i%2) {
                    CNOT(inputs[i], qs[0]);
                    (ControlledOnBitString([true, true], X))([inputs[i], qs[0]], qs[1]);
                    (ControlledOnBitString([true, true, true], X))([inputs[i], qs[0], qs[1]], qs[2]);
                    (ControlledOnBitString([true, true, true, true], X))([inputs[i], qs[0], qs[1], qs[2]], qs[3]);
                }
			}
		}
    }
}