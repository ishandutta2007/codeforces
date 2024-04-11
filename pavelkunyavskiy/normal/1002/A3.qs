namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits1 : Bool[], bits2 : Bool[]) : ()
    {
        body
        {
            mutable last = -1;
            for (i in 0..Length(qs)-1) {
               if (bits1[i] != bits2[i]) {
                  if (last == -1) {
                     H(qs[i]);
                     set last = i;
                  } else {
                     CNOT(qs[last], qs[i]);
                     if (bits1[i] != bits1[last]) {
                       X(qs[i]);
                     }   
                  }
               } elif (bits1[i] == true) {
                    X(qs[i]);
               }
            }
        }
    }
}