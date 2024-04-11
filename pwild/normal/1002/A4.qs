namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs: Qubit[]) : Unit {
        let n = Length(qs);

        if (n == 1) {
            X(qs[0]);
        } else {
            let k = n/2;
            Solve(qs[0..k-1]);

            using (anc = Qubit[1]) {
                let extra = anc[0];
                H(extra);
                for (i in 0..k-1) {
                    (Controlled SWAP)([extra],(qs[i],qs[i+k]));
                }

                for (i in k..n-1) {
                    CNOT(qs[i],extra);
                }
            }
        }
	}
}