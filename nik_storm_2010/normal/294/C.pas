const module=1000000007;
var
    c:array[-1..1000,-1..1000] of int64; a,d:array[0..1000] of int64; used:array[1..1000] of boolean;
      ans,kol,sum,n,m:int64; i,j:longint;


begin

  readln(n,m); d[0]:=1; ans:=1;
  for i:=0 to 1000 do c[i,0]:=1;
  for i:=1 to 1000 do for j:=1 to 1000 do c[i,j]:=(c[i-1,j-1]+c[i-1,j]) mod module;
  for i:=1 to 1000 do d[i]:=(d[i-1]*2) mod module;
  for i:=1 to m do
  begin
    read(a[i]); used[a[i]]:=true;
  end;
  i:=1; kol:=0;
  while i<=n do
    begin
      if used[i]=true then begin inc(i); continue; end;
      j:=i;
      while (j<=n) and (used[j]=false) do inc(j);
      inc(kol); a[kol]:=j-i;
      if (i<>1) and (j<>n+1) then ans:=(ans*d[a[kol]-1]) mod module;
      i:=j+1;
    end;
  sum:=n-m;
  for i:=1 to kol do
    begin
      ans:=(ans*c[sum,a[i]]) mod module;
      sum:=sum-a[i];
    end;
  writeln(ans);

end.