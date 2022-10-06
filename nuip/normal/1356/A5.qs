namespace Solution {
    //open Microsoft.Quantum.Convert;
    //open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    //open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    //open  Microsoft.Quantum.Diagnostics;
    // DumpMachine();

    operation Solve(unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable answer114514 = 0;
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            Controlled unitary([q1], q2);
            if (MResetX(q1) == One) {
               set answer114514 = 1;
            }
            Reset(q1);
            Reset(q2);
        }
        return answer114514;
    }
    //@EntryPoint()
    //operation Test (index : Int) : Unit { }

}