namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation XorAdjPairs (x : Qubit[], tmp : Qubit[]) : Unit {
    body (...) {
      let N = Length(x);
      for (i in 1..N-1) {
        CNOT(x[i-1], tmp[i-1]);
        CNOT(x[i], tmp[i-1]);
      }
    }
    adjoint auto;
  }

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      let N = Length(x);
      if (N == 1) {
        X(y);
      } else {
        using (tmp = Qubit[N-1]) {
          WithA(XorAdjPairs(x, _), Controlled X(_, y), tmp);
        }
      }
    }
    adjoint auto;
  }
}