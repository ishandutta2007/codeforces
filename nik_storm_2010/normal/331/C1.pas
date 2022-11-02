var
  f:array[0..1000000] of longint; n,c,i,x:longint;


begin

  readln(n);
  for i:=1 to n do
  begin
    c:=i; f[i]:=round(1e9);
    while c<>0 do
    begin
      x:=c mod 10; if f[i-x]+1<f[i] then f[i]:=f[i-x]+1;
      c:=c div 10;
    end;
  end;
  writeln(f[n]);

end.