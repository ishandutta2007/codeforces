namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    
    operation PrefixSums (x: Qubit[], p: Int) : Unit {
        body (...) {
            let n = Length(x);
            for (i in p..n-1) {
                X(x[i]);
                CNOT(x[i],x[i-p]);
                X(x[i]);
            }
        }
        adjoint auto;
    }
    
    operation FillAnc (x: Qubit[], anc: Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            for (p in 1..n-1) {
                PrefixSums(x,p);
                
                Controlled X(x[0..n-1-p],anc[p-1]);
                
                Adjoint PrefixSums(x,p);
            }
        }
        adjoint auto;
    }

    operation Solve (x: Qubit[], y: Qubit) : Unit {
        body (...) {
            let n = Length(x);
            
            using (anc = Qubit[n-1]) {
                FillAnc(x,anc);

                ApplyToEachCA(X,anc);
                Controlled X(anc,y);
                ApplyToEachCA(X,anc);
                X(y);
                
                Adjoint FillAnc(x,anc);
            }
        }
        adjoint auto;
	}

    operation Foo(N: Int) : Unit {
        Message(ToStringI(N));
        let size = 1 <<< N;
        using ((x,y) = (Qubit[N],Qubit())) {
            for (k in 0..size-1) {
                let binary = BoolArrFromPositiveInt(k,N);
                ApplyPauliFromBitString(PauliX, true, binary, x);
                
                //Message(ToStringI(k));

                Solve(x,y);
                
                if (M(y) == One) {
                    Message(ToStringI(k));
                }

                ResetAll(x);
                Reset(y);
            }
        }
    }
}