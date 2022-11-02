var
  a:array[1..1000] of longint; ans,cur,i,j,n:longint;


procedure reverse(i,j:longint;var cur:longint);
var t:longint;
begin
  cur:=0;
  for t:=1 to n do
    if (i<=t) and (t<=j) then cur:=cur+(1-a[t]) else cur:=cur+a[t];
end;


begin

  readln(n);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do
  begin
    for j:=i to n do
    begin
      reverse(i,j,cur);
      if cur>ans then ans:=cur;
    end;
  end;
  writeln(ans);

end.