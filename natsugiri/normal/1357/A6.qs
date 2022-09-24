namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Diagnostics;


    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            unitary(qs[1]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let m0 = M(qs[0]);
            let m1 = M(qs[1]);
            ResetAll(qs);
            if (m0 == Zero and m1 == Zero) {
                return 0; // I     
			} elif (m0 == Zero and m1 == One) {
                return 1; // X
			} elif (m0 == One and m1 == One) {
                return 2; // Y     
			} else {
                return 3; // Z  
			}
		}
    }
}