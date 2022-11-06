namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        mutable array = register!;
        let N = Length(array);
        for(val in array) {
            X(val);
        }
        for (i in 0..N-2) {
            (Controlled X)(array[0..(N-2-i)], array[(N-2-i)+1]);
        }
        X(array[0]);
        for(val in array) {
            X(val);
        }
    }
}