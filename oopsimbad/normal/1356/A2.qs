namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(q = Qubit()) {
            H(q);
            unitary(q);
            H(q);
            return MResetZ(q) == Zero ? 0 | 1;
        }
    }
    
    
    //@EntryPoint()
    operation HelloQ() : Unit {
       let res1 = Solve(I);
       Message($"Answer I: {res1}");
       let res2 = Solve(Z);
       Message($"Answer Z: {res2}");
    }
}