namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qubit = Qubit()) {
            unitary(qubit);
            let result = M(qubit);
            Reset(qubit);
            return result == One ? 1 | 0;
        }
    }
}