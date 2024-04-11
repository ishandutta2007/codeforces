namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int {
        body {
            CNOT(qs[1], qs[0]);
            H(qs[1]);

            mutable ans = 0;
            if (M(qs[0]) == One) {
                set ans = ans + 2;
            }
            if (M(qs[1]) == One) {
                set ans = ans + 1;
            }
            return ans;
        }
    }
}