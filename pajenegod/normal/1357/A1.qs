namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve(unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = false;
        using (register = Qubit[2])
        {
            X(register[0]);
            X(register[1]);
            unitary(register);
            set ans = M(register[0]) == Zero; 
            ResetAll(register);
        }
        if (ans) {
            return 1;
        } else {
            return 0;
        }
    }
    
    operation CNOT12(here : Qubit[]) : Unit is Adj + Ctl 
    { 
        CNOT(here[0], here[1]);
    }
    
    operation CNOT21(here : Qubit[]) : Unit is Adj + Ctl 
    { 
        CNOT(here[1], here[0]);
    }
    
    operation RunQsharp () : Int {
        return Solve(CNOT21);
    }
}