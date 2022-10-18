namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;
    
    function FindFirstDiff (bits0: Bool[], bits1: Bool[]) : Int {
        for (i in 0..Length(bits0)-1) {
            if (bits0[i] != bits1[i]) {
                return i;
            }
        }
        return -1;
    }

    operation PrepareIndex (index: Int, qs: Qubit[]) : Unit {
        body(...) {
            let n = Length(qs);
            let bits0 = BoolArrFromPositiveInt(index,n);
            let bits1 = BoolArrFromPositiveInt(index+1,n);
            
            let j = FindFirstDiff(bits0,bits1);

            if (bits0[j]) {
                X(qs[j]);
            }

            for (i in 0..n-1) {
                if (i != j) {
                    if (bits0[i]) {
                        X(qs[i]);
                    }
                    if (bits0[i] != bits1[i]) {
                        CNOT(qs[j],qs[i]);
                    }
                }
            }

            if (j != 0) {
                SWAP(qs[0],qs[j]);
            }
        }
        adjoint auto;
    }

    operation ControlledApplyAtIndex (unitary: (Qubit => Unit : Adjoint, Controlled), index: Int, qs: Qubit[]) : Unit {
        PrepareIndex(index,qs);
        
        (ControlledOnInt(0,unitary))(qs[1..Length(qs)-1],qs[0]);
        
        (Adjoint PrepareIndex)(index,qs);
    }

    operation Solve (qs: Qubit[]) : Unit {
        let n = Length(qs);
        let size = 1 <<< n;
        for (i in size-2..-1..0) {
            ControlledApplyAtIndex(H,i,qs);
        }
    }

    operation Foo (n: Int) : Unit {
        using (qs = Qubit[3]) {
            for (iter in 0..99) {
                let res = Solve(qs);
                ResetAll(qs);
            }
        }
    }
}