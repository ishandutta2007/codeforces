Uses
    math;
Var
    i1,i2,i3,x,y,z,klost: longint;
     k1,k2,k3: int64;


Begin

  readln(i1,i2,i3,klost);
   x:=max(i1,i2); x:=max(x,i3);
    z:=min(i1,i2); z:=min(z,i3);
     y:=i1+i2+i3-x-z;

  k3:=min(klost div 3,z-1);
   klost:=klost-k3;
    k2:=min(klost div 2,y-1);
     klost:=klost-k2;
      k1:=min(klost,x-1);

  writeln((k1+1)*(k2+1)*(k3+1));

End.