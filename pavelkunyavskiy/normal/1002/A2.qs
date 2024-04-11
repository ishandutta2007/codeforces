namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable last = -1;
            for (i in 0..Length(qs)-1) {
               if (bits[i] == true) {
                  if (last == -1) {
                     H(qs[i]);
                     set last = i;
                  } else {
                     CNOT(qs[last], qs[i]);
                  }
               } 
            }
        }
    }
}