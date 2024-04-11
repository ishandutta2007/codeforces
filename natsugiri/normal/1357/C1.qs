namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;

    operation Solve (qs : Qubit[]) : Unit {
        using (a = Qubit()) {                  
            repeat {
                ApplyToEachA(H, qs);
                Controlled X(qs, a);
                let m = MResetZ(a);
		    } until(m == Zero) fixup {
                ResetAll(qs);     
			}
		}
    }
}