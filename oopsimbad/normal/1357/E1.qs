namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        for(i in 1..p%4) {
            QFTLE(inputRegister);
        }
    }
}