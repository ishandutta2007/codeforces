namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
 
    function check(a : Double, b : Double) : Bool {
        return AbsD(PI()-a) < .1;
    }
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            mutable cur = 0.0;
                repeat {
                    set cur = cur+theta;
                    if(cur >= 2.0*PI()) {
                        set cur -= 2.0*PI();
                    }
                    unitary(q);
                } until(check(cur, theta));
            if(MResetZ(q) == One) {
                return 1;
            }
        }
        return 0;
    }
    //love that
    //weee
}