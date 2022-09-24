namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;  
    open Microsoft.Quantum.Diagnostics;

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(inputs);

        using (qs = Qubit[11]) {
            for (i in 0..n-1) {
                for (j in i..-1..0) {
                    (Controlled X)([inputs[i], qs[j]], qs[j+1]);
				}
                CNOT(inputs[i], qs[0]);
			}

            if (n == 2) {
                (ControlledOnBitString([true, false], X))(qs[0..1], output);
            } elif (n == 4) {
                (ControlledOnBitString([false, true, false, false], X))(qs[0..3], output);
            } elif (n == 6) {
                (ControlledOnBitString([true, true, true, false, false, false], X))(qs[0..5], output);       
            } elif (n == 8) {
                (ControlledOnBitString([false, false, false, true, false, false, false, false], X))(qs[0..7], output);
            } elif (n == 10) {
                (ControlledOnBitString([true, false, false, true, true, false, false, false, false, false], X))(qs[0..9], output);
			}

            for (i in n-1..-1..0) {
                CNOT(inputs[i], qs[0]);
                for (j in 0..i) {
                    (Controlled X)([inputs[i], qs[j]], qs[j+1]);
				}
			}
		}
    }
}