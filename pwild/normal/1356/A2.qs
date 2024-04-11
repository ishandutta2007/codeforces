namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qubit = Qubit()) {
            H(qubit);
            unitary(qubit);
            H(qubit);
            let result = M(qubit);
            Reset(qubit);
            return result == One ? 1 | 0;
        }
    }
}