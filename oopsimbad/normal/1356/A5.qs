namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(qs = Qubit[2]) {
            H(qs[1]);
            (Controlled unitary)([qs[1]], qs[0]);
            H(qs[1]);
            let res = MResetZ(qs[1]) == Zero ? 0 | 1;
            ResetAll(qs);
            return res;
        }
    }
}