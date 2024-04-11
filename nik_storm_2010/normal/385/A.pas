var
  a:array[1..1000] of longint;
  ans,cur,n,c,i:longint;

begin
  readln(n,c);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n-1 do
  begin
    cur:=a[i]-a[i+1]-c;
    if (cur>ans) then ans:=cur;
  end;
  writeln(ans);
end.