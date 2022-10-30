var
    a,f:array[0..100001] of longint; answer,tek,nom,n,k,i:longint;


begin

  readln(n,k); for i:=1 to n do read(a[i]);
  tek:=0;
  for i:=1 to n do
    if a[i]<>a[tek] then
    begin
      inc(tek);
      a[tek]:=a[i];
    end;
  a[0]:=a[1]; a[tek+1]:=a[tek];
  for i:=1 to tek do
    begin
      if a[i-1]<>a[i+1] then f[a[i]]:=f[a[i]]+1 else f[a[i]]:=f[a[i]]+2;
    end;
  answer:=-1; nom:=0;
  for i:=1 to k do
    if f[i]>answer then
    begin
      answer:=f[i];
      nom:=i;
    end;
  writeln(nom);

end.