uses
  math;
var
  a:array[1..200000] of longint;
  ans,n,l,r,i:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  r:=1;
  ans:=0;
  for l:=1 to n do
  begin
    while (r<=n) do
    begin
      if (r-l<2) then begin inc(r); continue; end;
      if (a[r]=a[r-1]+a[r-2]) then inc(r) else break;
    end;
    ans:=max(ans,r-l);
  end;
  writeln(ans);
end.