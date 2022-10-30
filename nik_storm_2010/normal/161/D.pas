var
    f:array[1..50000,-1..500] of int64; g:array[1..2,1..100000] of longint; st:array[1..50000] of longint;
      used:array[1..50000] of boolean; n,k,a,b,i:longint; ans:int64;


procedure rec(nom:longint);
var i,j:longint;
begin
  used[nom]:=true; i:=st[nom];
  while i<>0 do
    begin
      if used[g[1,i]]=false then
        begin
          rec(g[1,i]);
          for j:=0 to k do
            if (f[g[1,i],j]<>0) then ans:=ans + (f[g[1,i],j]*f[nom,k-(j+1)]);
          for j:=1 to k do f[nom,j]:=f[nom,j]+f[g[1,i],j-1];
        end;
      i:=g[2,i];
    end;
  f[nom,0]:=1; ans:=ans+f[nom,k];
end;


begin

  readln(n,k);
  for i:=1 to n-1 do
    begin
      readln(a,b);
      g[1,i*2-1]:=b; g[2,i*2-1]:=st[a]; st[a]:=i*2-1;
      g[1,i*2]:=a; g[2,i*2]:=st[b]; st[b]:=i*2;
    end;
  ans:=0; rec(1);
  writeln(ans);

end.