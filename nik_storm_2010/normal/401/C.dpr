const
  l=2000000;
var
  a:array[0..l] of longint;
  n,m,mi,ma,s,i,j:longint;

procedure bad;
begin
  writeln(-1);
  halt;
end;

begin
  readln(n,m);
  mi:=n-1;
  if (m<mi) then bad;
  ma:=(n+1)*2;
  if (m>ma) then bad;
  if (2*n>=m) then s:=1 else s:=0;
  for i:=s to n do
  begin
    if (m=0) then break;
    a[i]:=1;
    dec(m);
  end;
  for i:=s to n do
  begin
    if (m=0) then break;
    inc(a[i]);
    dec(m);
  end;
  if (s=1) then write(0);
  for i:=s to n do
  begin
    for j:=1 to a[i] do write(1);
    if (i<>n) then write(0);
  end;
end.