Uses
    math;
Var
    a: array[1..100000] of int64;
     t: array[1..100000] of int64;
      ost: array[0..100000] of int64;
       k1,k2,k3,t1,t2,t3,n,m: int64;
        i: longint;



Begin

  readln(k1,k2,k3);
   readln(t1,t2,t3);
    readln(n);
     for i:=1 to n do read(a[i]);

  for i:=1 to n do
   begin
    t[i]:=max(a[i],ost[i mod k1])+t1;
     ost[i mod k1]:=t[i];
   end;

  fillchar(ost,sizeof(ost),0);
   for i:=1 to n do
    begin
     t[i]:=max(t[i],ost[i mod k2])+t2;
      ost[i mod k2]:=t[i];
    end;

  fillchar(ost,sizeof(ost),0);
   for i:=1 to n do
    begin
     t[i]:=max(t[i],ost[i mod k3])+t3;
      ost[i mod k3]:=t[i];
    end;

  m:=0;
   for i:=1 to n do
    if t[i]-a[i] > m then m:=t[i]-a[i];
  writeln(m);

End.