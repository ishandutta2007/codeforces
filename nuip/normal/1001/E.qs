namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Int  {
        CNOT(qs[0], qs[1]);
        mutable re = 0;
        if (M(qs[1]) == One){
            set re = re + 2;
        } 
        if (MResetX(qs[0]) == One) {
            set re = re + 1;
        }
        return re;
    }

    //@EntryPoint()
    operation Test (index : Int) : Int {
        mutable re = 0;
        for(i in 1..10) {
        using (qs = Qubit[2]) {
        if(index%2==1){
            X(qs[0]);
        }
        H(qs[0]);
        if(index>=2){
            X(qs[1]);
        }
        CNOT(qs[0], qs[1]);
        let res = Solve(qs);
        set re = re * 10 + res;
        ResetAll(qs);
        }
    }
        return re;
    }
}