var
  a,will:array[0..100] of longint; t:array[1..1000000] of longint;
  q:array[1..200000] of longint; n,m,i,x,y:longint;


procedure build(tp,nom,l,r:longint);
var m:longint;
begin
  if (l=r) then t[nom]:=q[l] else
  begin
    m:=(l+r) div 2;
    build(tp+1,nom*2,l,m);
    build(tp+1,nom*2+1,m+1,r);
    if (will[tp]=1) then t[nom]:=t[nom*2] or t[nom*2+1] else t[nom]:=t[nom*2] xor t[nom*2+1];
  end;
end;


procedure modify(tp,nom,l,r,w,d:longint);
var m:longint;
begin
  if (l=r) then t[nom]:=d else
  begin
    m:=(l+r) div 2;
    if (w<=m) then modify(tp+1,nom*2,l,m,w,d) else modify(tp+1,nom*2+1,m+1,r,w,d);
    if (will[tp]=1) then t[nom]:=t[nom*2] or t[nom*2+1] else t[nom]:=t[nom*2] xor t[nom*2+1];
  end;
end;


begin
  a[0]:=1; for i:=1 to 17 do a[i]:=a[i-1]*2;
  readln(n,m);
  if (n mod 2=1) then
  begin
    for i:=1 to n do if (odd(i)) then will[i]:=1 else will[i]:=0;
  end
    else
  begin
    for i:=1 to n do if (odd(i)) then will[i]:=0 else will[i]:=1;
  end;
  for i:=1 to a[n] do read(q[i]);
  build(1,1,1,a[n]);
  for i:=1 to m do
  begin
    readln(x,y);
    modify(1,1,1,a[n],x,y);
    writeln(t[1]);
  end;
end.