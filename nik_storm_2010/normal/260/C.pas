var
    a:array[1..100000] of int64; koef,n:int64; nom,min,i,x:longint;


begin

  readln(n,x); for i:=1 to n do read(a[i]);
  min:=maxlongint; i:=x;
  while true do
    begin
      if a[i]<min then begin min:=a[i]; nom:=i; end;
      dec(i); if i=0 then i:=n;
      if i=x then break;
    end;
  koef:=a[nom]; a[nom]:=0; i:=x;
  while i<>nom do
    begin
      dec(a[i]); inc(a[nom]);
      dec(i); if i=0 then i:=n;
    end;
  for i:=1 to n do
    if i=nom then write(a[nom]+koef*n,' ') else write(a[i]-koef,' ');

end.