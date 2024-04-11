namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], index : Int) : ()  {
        if(index%2==1){
            X(qs[0]);
        }
        H(qs[0]);
        if(index>=2){
            X(qs[1]);
        }
        CNOT(qs[0], qs[1]);
    }
}