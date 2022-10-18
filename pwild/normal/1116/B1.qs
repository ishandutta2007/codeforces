namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;
    
    function valArray () : ComplexPolar[] {
        let alpha = 2.0*PI()/3.0;
        mutable arr = new ComplexPolar[8];
        for (i in 0..2) {
            set arr[1 <<< i] = ComplexPolar(1.0,ToDouble(2-i)*alpha);
        }
        return arr;
    }

    operation Prep (qs: Qubit[]) : Unit {
        body (...) {
            let arr = valArray();
            PrepareArbitraryState(arr,BigEndian(qs));
        }
        adjoint auto;
    }

    operation Solve (qs: Qubit[]) : Int {
        (Adjoint Prep)(qs);
        
        for (i in 0..2) {
            if (M(qs[i]) == One) {
                return 1;
            }
        }
        return 0;
    }

    operation Foo(N: Int) : Unit {
        using (qs = Qubit[3]) {
            for (iter in 0..99) {
                Prep(qs);
                
                DumpMachine();
                
                let res = Solve(qs);
                Message(ToStringI(res));
                
                ResetAll(qs);
            }
        }
    }
}