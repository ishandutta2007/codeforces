namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qubits = Qubit[2]) {
            unitary(qubits);
            let result = M(qubits[1]);
            ResetAll(qubits);
            return result == One ? 0 | 1;
        }
    }
}