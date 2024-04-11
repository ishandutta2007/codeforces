namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        for (i in 0..Length(qs)-1) {
            if (bits0[i] != bits1[i]) {
                if ((M(qs[i]) == Zero) == (bits0[i] == false)) {
                    return 0;
                }
                return 1;
            }
        }
        return -1;
    }
}