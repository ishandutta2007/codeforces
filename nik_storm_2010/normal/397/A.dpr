const
  lim=1000;
var
  used:array[0..lim] of boolean;
  l,r:array[0..lim] of longint;
  ans,n,i,j:longint;

begin
  readln(n);
  for i:=1 to n do readln(l[i],r[i]);
  for i:=2 to n do for j:=l[i]+1 to r[i] do used[j]:=true;
  for i:=l[1]+1 to r[1] do if (not used[i]) then inc(ans);
  writeln(ans);
end.