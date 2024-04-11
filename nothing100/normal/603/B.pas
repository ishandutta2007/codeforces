const mo=1000000007;
var
  ans:int64;
  n,m,len:longint;
  bo:array [0..1000000] of boolean;
  f:array [0..1000000] of longint;
procedure dfs(x:int64);
begin
  bo[x]:=true;
  inc(len);
  if not bo[(m*x) mod n] then dfs((m*x) mod n);
end;
procedure init;
var
  i,j:longint;
  tmp,tmpp:int64;
begin
  read(n,m);
  bo[0]:=true;
  for i:=1 to n-1 do
  if not bo[i] then
  begin
    len:=0;
    dfs(i);
    inc(f[len]);
  end;
  ans:=1;
  for i:=1 to n do
  begin
    tmp:=f[i]*i+1;
    tmpp:=1;
    for j:=1 to f[i] do tmpp:=(tmpp*tmp) mod mo;
    ans:=(ans*tmpp) mod mo;
  end;
  if m=1 then ans:=(ans*n) mod mo;
  writeln(ans);
end;
begin
  init;
end.