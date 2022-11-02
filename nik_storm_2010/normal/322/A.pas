var
  un,um:array[1..100] of boolean; a:array[1..2,1..100000] of longint;
  n,m,ans,i,j:longint;


begin

  readln(n,m);
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
    if (un[i]=false) or (um[j]=false) then
    begin
      un[i]:=true; um[j]:=true;
      inc(ans); a[1,ans]:=i; a[2,ans]:=j;
    end;
  writeln(ans);
  for i:=1 to ans do writeln(a[1,i],' ',a[2,i]);

end.