uses math;
var
    a:array[1..100000,1..2] of longint; mi,ma,n,i:longint;


begin

  readln(n); mi:=maxlongint; ma:=0;
  for i:=1 to n do
    begin
      readln(a[i,1],a[i,2]);
      mi:=min(mi,a[i,1]); ma:=max(ma,a[i,2]);
    end;
  for i:=1 to n do
    if (a[i,1]<=mi) and (ma<=a[i,2]) then
    begin
      writeln(i); halt;
    end;
  writeln(-1);

end.