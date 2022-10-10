namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Calculate (qs : Qubit[], tmp : Qubit[]) : Unit {
        body (...) {
          let N = Length(qs);
          for (i in 1..N) {
            (ControlledOnInt(0, X))([tmp[i-1], qs[N-i]], tmp[i]);
            X(tmp[i]);
          }
        }
        adjoint auto;
    }

    operation Apply (tmp : Qubit[], qs : Qubit[]) : Unit {
        body (...) {
          let N = Length(qs);
          for (i in 1..N) {
            Controlled H([tmp[i-1]], qs[N-i]);
          }
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        using (tmp = Qubit[N+1]) {
          WithA(Calculate(qs, _), Apply(_, qs), tmp);
        }
    }
}