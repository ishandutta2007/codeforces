namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        for (i in 1 .. p%4) {
            QFTLE(inputRegister);
        }
    }
}