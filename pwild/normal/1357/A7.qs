namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation FindSign (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            (Controlled unitary)([qs[0]], qs[1]);
            H(qs[0]);
            let result = M(qs[0]);
            ResetAll(qs);
            return result == Zero ? 1 | -1;
        }
    }

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        let op = BoundCA([unitary, Y]);
        let a = FindSign(OperationPowCA(op, 2));
        if (a == 1) { // Y or -Y
            return FindSign(op) == 1 ? 0 | 2;
        } else { // XZ or -XZ
            return FindSign(BoundCA([op,Z,X,Y])) == 1 ? 1 | 3;
        }
    }
}