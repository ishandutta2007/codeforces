var
  prev,next,lose,f:array[-1..1000000] of longint;
  n,m,i,j,l,r,x,z:longint;

function findset(x:longint):longint;
begin
  if (f[x]<>x) then f[x]:=findset(f[x]);
  findset:=f[x];
end;

procedure union(x,y:longint);
begin
  x:=findset(x);
  y:=findset(y);
  f[y]:=x;
end;

begin
  randomize;
  readln(n,m);
  for i:=1 to n do begin prev[i]:=i-1; next[i]:=i+1; f[i]:=i; end;
  for i:=1 to m do
  begin
    readln(l,r,x);
    j:=findset(l);
    while (j<=r) do
    begin
      if (j=x) then begin j:=next[j]; continue; end;
      lose[j]:=x;
      union(x,j);
      next[prev[j]]:=next[j];
      prev[next[j]]:=prev[j];
      j:=next[j];
    end;
  end;
  for i:=1 to n do write(lose[i],' ');
end.