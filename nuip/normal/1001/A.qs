namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit, sign : Int) : ()  {
        if(sign==1){
            H(q);
        }else{
            X(q);
            H(q);
        }
    }
}