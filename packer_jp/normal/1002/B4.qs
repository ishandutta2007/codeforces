namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int {
        body {
            (Controlled Z)([qs[0]],(qs[1]));
            mutable res = 0;
            H(qs[0]);
            H(qs[1]);
            if(M(qs[0])==One){
                set res=res+1;
            }
            if(M(qs[1])==One){
                set res=res+2;
            }
            return 3-res;
        }
    }

}