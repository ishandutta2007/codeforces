namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    
    function PopCount (x: Int) : Int {
        mutable res = 0;
        mutable bit = 1;
        repeat {
            if ((x &&& bit) > 0) {
                set res = res+1;
            }
            set bit = 2*bit;
        } until (bit > x)
        fixup { }
        return res;
    }
    
    function SliceWithMask (x: Qubit[], mask: Int) : Qubit[] {
        let n = Length(x);
        let k = PopCount(mask);
        mutable arr = new Qubit[k];
        mutable j = 0;
        for (i in 0..n-1) {
            if ((mask &&& (1 <<< i)) > 0) {
                set arr[j] = x[i];
                set j = j+1;
            }
        }
        return arr;
    }


    operation Solve (x: Qubit[], y: Qubit) : Unit {
        body (...) {
            let n = Length(x);
            let size = 1 <<< n;
            
            X(y);

            for (mask in 1..size-1) {
                let k = PopCount(mask);
                if (k % 3 != 0) {
                    let arr = SliceWithMask(x,mask);
                    Controlled X(arr,y);
                }
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

                Solve(x,y);
                
                if ((PopCount(k)%3 == 0) != (M(y) == One)) {
                    Message(ToStringI(k) + " " + ToStringI(PopCount(k)));
                    Message(ToStringB(PopCount(k)%3 == 0));
                }

                ResetAll(x);
                Reset(y);
            }
        }
    }
}