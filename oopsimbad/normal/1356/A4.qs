namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using(qs = Qubit[2]) {
            unitary(qs);
            let res = MResetZ(qs[1]) == Zero ? 1 | 0;
            ResetAll(qs);
            return res;
        }
    }
}