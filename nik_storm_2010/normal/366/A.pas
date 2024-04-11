uses
  math;
var
  a,b,c,d,n,i:longint;

begin
  readln(n);
  for i:=1 to 4 do
  begin
    readln(a,b,c,d);
    a:=min(a,b);
    c:=min(c,d);
    if (a+c<=n) then begin writeln(i,' ',a,' ',n-a); halt; end;
  end;
  writeln(-1);
end.