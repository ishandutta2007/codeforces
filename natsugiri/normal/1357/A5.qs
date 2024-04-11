namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    
    open Microsoft.Quantum.Measurement;
    
    open Microsoft.Quantum.Diagnostics;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable sum = 0.0;
        mutable cnt = 0;
        repeat {
            set cnt = cnt + 1;
            set sum = sum + theta;
            if (sum > 1.4 * PI()) {
                set sum = sum - PI();     
			}
		} until (0.6 * PI() <= sum and sum <= 1.4 * PI());

        mutable a0 = 0;
        mutable a1 = 0;
        using (q = Qubit()) {
            repeat {
                for (i in 1..cnt) {
                    unitary(q);     
			    }
                let m = MResetZ(q);
                if (m == Zero) {
                    set a0 = a0 + 1;     
			    } else {
                    set a1 = a1 + 1;     
			    }                        
			} until (a1 > 0 or a0 == 40);
		}

        // Message($"{sum} {cnt} {a0} {a1}");

        if (a1 > 0) {
            return 1;  
		} else {
            return 0;  
		}
    }
}