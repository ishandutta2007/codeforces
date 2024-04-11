uses
  math;
var
  finish:array[0..50000,0..5] of int64;
  m,n,i,j:longint;
  x:int64;

begin
  readln(m,n);
  for i:=1 to m do
  begin
    for j:=1 to n do
    begin
      read(x);
      finish[i,j]:=max(finish[i,j-1],finish[i-1,j])+x;
    end;
    readln;
  end;
  for i:=1 to m do writeln(finish[i,n]);
end.