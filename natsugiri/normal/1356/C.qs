namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;
   
    operation Solve (qs : Qubit[]) : Unit {
        using (a = Qubit()) {                  
            repeat {
                H(qs[0]);
                H(qs[1]); 
                Controlled X(qs, a);
                let m = MResetZ(a);
		    } until(m == Zero) fixup {
                ResetAll(qs);     
			}
            X(qs[0]);
            X(qs[1]);
		}
    }
}