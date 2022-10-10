namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation SolveForAllPeriods (x : Qubit[], tmp : Qubit[], res : Qubit[]) : Unit {
    body (...) {
      let N = Length(x);
      let p = N - Length(tmp);
          for (i in 0..N-p-1) {
            CNOT(x[i+p], tmp[i]);
            X(tmp[i]);
          }
          Controlled X(tmp, res[p-1]);
          for (i in 1..N-p) {
            X(tmp[N-p-i]);
            CNOT(x[N-i], tmp[N-p-i]);
          }
          X(res[p-1]);
        if (p+1<N) {
          SolveForAllPeriods(x, Most(tmp), res);
        }
    }
    adjoint auto;
  }

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      let N = Length(x);
      if (N > 1) {
        using (res = Qubit[N-1]) {
          WithA(SolveForAllPeriods(x, Most(x), _), Controlled X(_, y), res);
        }
      }
      X(y);
    }
    adjoint auto;
  }
}