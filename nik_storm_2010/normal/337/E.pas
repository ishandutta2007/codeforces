const l=1000000;
var
  a,b:array[1..8] of int64; pr:array[1..l] of int64; used:array[1..l] of boolean;
  ok:array[1..8] of boolean; ans,n,i,j,k:longint; w,x,y:int64;


function find(r:longint):longint;
var res,i:longint; x:int64;
begin
  res:=0; i:=1; x:=a[r];
  while (pr[i]*pr[i]<=x) and (i<=k) do
  begin
    while (x mod pr[i]=0) do begin inc(res); x:=x div pr[i]; end;
    inc(i);
  end;
  if (x<>1) then if (res=0) then ok[r]:=true else inc(res);
  find:=res;
end;


procedure rec(nom,ost,rt:longint);
var i:longint;
begin
  if (nom=n+1) then
  begin
    if (rt>1) then inc(ost); ost:=ost+n;
    if (ans>ost) then ans:=ost; exit;
  end;
  rec(nom+1,ost,rt+1);
  for i:=nom-1 downto 1 do
    if (a[i] mod a[nom]=0) then
    begin
      a[i]:=a[i] div a[nom];
      if (ok[nom]) then rec(nom+1,ost-1,rt) else rec(nom+1,ost-b[nom],rt);
      a[i]:=a[i]*a[nom];
    end;
end;


begin
  readln(n); for i:=1 to n do read(a[i]);
  for i:=1 to n do for j:=i+1 to n do
    if (a[i]<a[j]) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
    end;
  x:=2;
  while (x<=l) do
  begin
    if (not used[x]) then
    begin
      inc(k); pr[k]:=x; y:=x*x;
      while (y<=l) do begin used[y]:=true; y:=y+x; end;
    end;
    inc(x);
  end;
  ans:=maxlongint; x:=0;
  for i:=1 to n do begin b[i]:=find(i); x:=x+b[i]; end;
  rec(1,x,0);
  writeln(ans);
end.