var
    a,b:array[1..1000] of longint; used:array[1..1000] of boolean; ans,n,i,j:longint;


begin

  readln(n);
  for i:=1 to n do readln(a[i],b[i]);
  fillchar(used,sizeof(used),false);
  ans:=0;
  for i:=1 to n do
    for j:=1 to n do
    if (i<>j) and (a[i]=b[j]) then
    begin
      if used[i]=false then inc(ans);
      used[i]:=true;
    end;
  writeln(n-ans);

end.