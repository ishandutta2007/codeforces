uses
  math;
var
  a:array[1..10000] of longint;
  n,i,j,x,y,z,w:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do for j:=1 to n-1 do
  if (i<>j) then
  begin
    x:=min(a[i],a[i+1]);
    y:=max(a[i],a[i+1]);
    z:=min(a[j],a[j+1]);
    w:=max(a[j],a[j+1]);
    if (x<z) and (z<y) and (y<w) then
    begin
      writeln('yes');
      halt;
    end;
  end;
  writeln('no');
end.