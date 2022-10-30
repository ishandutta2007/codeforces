uses
  math;
var
  ans,c1,c2,c3,c4,c5:extended;

begin
  readln(c1,c2,c3,c4,c5);
  ans:=1e9;
  ans:=min(ans,c1/1);
  ans:=min(ans,c2/1);
  ans:=min(ans,c3/2);
  ans:=min(ans,c4/7);
  ans:=min(ans,c5/4);
  writeln(trunc(ans));
end.