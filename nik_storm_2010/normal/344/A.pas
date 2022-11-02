var
  prev,ans,n,i,x:longint;

begin
  readln(n); ans:=1;
  readln(prev);
  for i:=2 to n do
  begin
    readln(x);
    if (x<>prev) then inc(ans);
    prev:=x;
  end;
  writeln(ans);
end.