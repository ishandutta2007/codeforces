namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;  
    open Microsoft.Quantum.Diagnostics;



    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            (Controlled unitary)(qs[0..0], qs[1]);
            (Controlled unitary)(qs[0..0], qs[1]);
            if (MResetX(qs[0]) == Zero) {
                H(qs[0]);
                (Controlled Y)(qs[0..0], qs[1]);
                (Controlled unitary)(qs[0..0], qs[1]);
                return MResetX(qs[0]) == Zero ? 0 | 2;
			} else {
                H(qs[0]);
                (Controlled X)(qs[0..0], qs[1]);
                (Controlled Z)(qs[0..0], qs[1]);
                (Controlled unitary)(qs[0..0], qs[1]);
                return MResetX(qs[0]) == Zero ? 3 | 1;
			}
		}
    }

    operation SolveA6 (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[0]);
            X(qs[1]);
            H(qs[0]);
            DumpMachine("");
            (Controlled unitary)(qs[0..0], qs[1]);
           DumpMachine("");

            let x = MResetX(qs[0]);
            let y = MResetX(qs[1]);
            Message($"{x} {y}");
            ResetAll(qs);
            return 0;
        }
    }
}