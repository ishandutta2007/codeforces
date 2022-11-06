namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(q = Qubit()) {
            H(q);
            unitary(q);
            unitary(q);
            H(q);
            return MResetZ(q) == Zero ? 0 | 1;
        }
    }
}