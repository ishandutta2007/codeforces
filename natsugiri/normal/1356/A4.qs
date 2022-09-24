namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            unitary(qs);
            let m = M(qs[1]);
            ResetAll(qs);
            if (m == One) {
                return 0; // I \times X
			} else {
                return 1; // CNOT
			}
		}
    }
}