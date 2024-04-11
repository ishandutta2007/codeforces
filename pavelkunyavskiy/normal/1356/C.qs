namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit[]) : Unit {
        using (extra = Qubit()) {            
            repeat {
                Reset(extra); Reset(q[0]); Reset(q[1]);
	        H(q[0]); H(q[1]);
        	Controlled X(q, extra);
            } until (M(extra) == Zero);
        }
        X(q[0]); X(q[1]);
    }
}