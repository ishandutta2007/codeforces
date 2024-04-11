var
  a:array[-1..9] of longint; n,k,i:longint;


begin

  readln(n); k:=0;
  while n<>0 do
  begin
    inc(k); a[k]:=n mod 10;
    n:=n div 10;
  end;
  i:=k;
  while i<>0 do
  begin
    if (a[i]=1) and (a[i-1]=4) and (a[i-2]=4) then i:=i-3 else
    if (a[i]=1) and (a[i-1]=4) then i:=i-2 else
    if (a[i]=1) then i:=i-1 else
    begin
      writeln('NO');
      halt;
    end;
  end;
  writeln('YES');

end.