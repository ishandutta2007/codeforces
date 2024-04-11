namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs: Qubit[], bits: Bool[][]) : Unit {
        let n = Length(qs);
        
        using (anc = Qubit[2]) {
            ApplyToEach(H,anc);
            for (i in 0..3) {
                let transform = ApplyPauliFromBitString(PauliX, true, bits[i], _);
                (ControlledOnInt(i,transform))(anc,qs);
            }
            for (i in 0..3) {
                let j = PositiveIntFromBoolArr(bits[i]);
                let transform = ApplyPauliFromBitString(PauliX, true, BoolArrFromPositiveInt(i,2), _);
                (ControlledOnInt(j,transform))(qs,anc);
            }
        }
    }

    operation Foo(N: Int) : Unit {
        Message(ToStringI(N));
        let size = 1 <<< N;
        using (qs = Qubit[N]) {
            for (iter in 0..99) {
                mutable ints = new Int[4];
                for (i in 0..3) {
                    set ints[i] = RandomInt(size);
                }
                
                mutable distinct = true;
                for (i in 0..3) {
                    for (j in i+1..3) {
                        if (ints[i] == ints[j]) {
                            set distinct = false;
                        }
                    }
                }

                if (distinct) {
                    mutable bits = new Bool[][4];
                    for (i in 0..3) {
                        Message(ToStringI(ints[i]));
                        set bits[i] = BoolArrFromPositiveInt(ints[i],N);
                    }
                    
                    Solve(qs,bits);
                    DumpMachine();
                }
                
                ResetAll(qs);
            }
        }
    }
}