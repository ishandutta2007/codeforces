namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            H(qs[1]);
            (Controlled unitary)([qs[1]], (PI()*2.0, qs[0]));
            H(qs[1]);
            H(qs[0]);
            //DumpMachine("");
            let m = M(qs[1]);
            ResetAll(qs);
            if (m == Zero) {
                return 1;     
			} else {
                return 0;     
			}
		}
    }
}