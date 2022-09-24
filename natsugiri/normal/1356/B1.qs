namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        let qs = register!;
        let n = Length(qs);
        X(qs[0]);
        for (i in 1..n-1) {
            (ControlledOnInt(0, X))(qs[0..i-1], qs[i]);
		}
    }
}