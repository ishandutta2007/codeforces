uses math;
var
    g:array[1..100,1..100] of int64; n,i,j,k,s,t,x:longint;


begin

  readln(n);
  for i:=1 to n do for j:=1 to n do g[i,j]:=maxlongint;
  for i:=1 to n do
    begin
      read(x);
      if i=n then begin g[1,n]:=x; g[n,1]:=x; end
             else begin g[i,i+1]:=x; g[i+1,i]:=x; end;
    end;
  readln; readln(s,t);
  if s=t then begin writeln(0); halt; end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
      if g[i,j]>g[i,k]+g[k,j] then g[i,j]:=g[i,k]+g[k,j];
  writeln(g[s,t]);

end.