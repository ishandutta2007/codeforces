namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Calculate (x : Qubit[], tmp : Qubit[]) : Unit {
    body (...) {
      let N = Length(x);
      X(tmp[0]);
      for (i in 0..N-1) {
        CCNOT(x[i], tmp[2], tmp[3]);
        CCNOT(x[i], tmp[1], tmp[2]);
        CCNOT(x[i], tmp[0], tmp[1]);
        CCNOT(x[i], tmp[3], tmp[2]);
        CCNOT(x[i], tmp[2], tmp[1]);
        CCNOT(x[i], tmp[1], tmp[0]);
        CCNOT(x[i], tmp[3], tmp[0]);
        CCNOT(x[i], tmp[0], tmp[3]);
      }
    }
    adjoint auto;
  }

  operation Apply (tmp : Qubit[], y : Qubit) : Unit {
    body (...) {
      CNOT(tmp[0], y);
    }
    adjoint auto;
  }

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      let N = Length(x);
      using (tmp = Qubit[4]) {
        WithA(Calculate(x, _), Apply(_, y), tmp);
      }
    }
    adjoint auto;
  }
}