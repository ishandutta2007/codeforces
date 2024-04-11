var
  a:array[1..1000,1..1000] of char;
  ans,n,i,j:longint;

begin
  readln(n);
  ans:=0;
  for i:=1 to n do for j:=1 to n do if (i+j) mod 2=0 then
  begin
    a[i,j]:='C';
    inc(ans);
  end
  else a[i,j]:='.';
  writeln(ans);
  for i:=1 to n do
  begin
    for j:=1 to n do write(a[i,j]);
    writeln;
  end;
end.