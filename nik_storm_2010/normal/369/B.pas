var
  a:array[1..100000] of longint;
  n,k,l,r,sall,sk,i:longint;

procedure build(x:longint);
var
  i:longint;
begin
  sall:=sall-sk;
  sk:=sk-k*x;
  for i:=1 to k do a[i]:=x;
  i:=1;
  while (sk<>0) do
  begin
    inc(a[i]);
    inc(i);
    if (i>k) then begin inc(x); i:=1; end;
    dec(sk);
  end;
  for i:=k+1 to n do begin a[i]:=l; sall:=sall-l; end;
  i:=k+1;
  while (sall<>0) do
  begin
    inc(a[i]);
    inc(i);
    if (i>n) then i:=k+1;
    dec(sall);
  end;
  for i:=1 to n do write(a[i],' ');
  halt;
end;

begin
  readln(n,k,l,r,sall,sk);
  for i:=l to r do if (i*k<=sk) and ((i+1)*k>sk) then build(i);
end.