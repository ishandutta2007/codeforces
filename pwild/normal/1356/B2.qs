namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Incr (register : LittleEndian) : Unit is Adj+Ctl {
        let qs = register!;
        let n = Length(qs);
        for (i in n-1 .. -1 .. 1) {
            (Controlled X)(qs[0..i-1], qs[i]);
        }
        X(qs[0]);
    }

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        (Adjoint Incr)(register);
    }
}