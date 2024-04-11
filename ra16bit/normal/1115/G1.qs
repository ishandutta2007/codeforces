namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  operation Solve (qs : Qubit[]) : Unit {
    body (...) {
      mutable finished = false;
      repeat {
        H(qs[0]);
        H(qs[1]);
        using (ancilla = Qubit()) {
          CCNOT(qs[0], qs[1], ancilla);
          if (M(ancilla) == Zero) {
            set finished = true;
          }
          Reset(ancilla);
        }
      } until(finished)
      fixup {
      }
    }
  }
}