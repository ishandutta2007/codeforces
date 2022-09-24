namespace Solution {
    open Microsoft.Quantum.Intrinsic;

     operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            H(q);
            unitary(q);
            unitary(q);
            H(q);
            let m = M(q);
            Reset(q);
            if (m == Zero) {
                return 0; // Z
			} else {
                return 1; // S
			}
		}
    }
}