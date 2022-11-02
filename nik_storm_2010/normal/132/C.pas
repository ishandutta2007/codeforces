uses
  math;
const
  l=100;
var
  f:array[-l..l,0..l,0..l,0..1] of boolean;
  ans,x,i,j,k,d,n,take,nx:longint;
  c:char;
  s:ansistring;

begin
  readln(s);
  d:=length(s);
  readln(n);
  f[0,0,0,1]:=true;
  for i:=0 to d-1 do for x:=-l to l do for j:=0 to n do for k:=0 to 1 do
  begin
    if (not f[x,i,j,k]) then continue;
    for take:=0 to n-j do
    begin
      c:=s[i+1];
      if (odd(take)) then if (c='F') then c:='T' else c:='F';
      if (c='T') then f[x,i+1,j+take,1-k]:=true else
      begin
        if (k=1) then nx:=x+1 else nx:=x-1;
        f[nx,i+1,j+take,k]:=true;
      end;
    end;
  end;
  ans:=0;
  for x:=-l to l do for k:=0 to 1 do if (f[x,d,n,k]) then ans:=max(ans,abs(x));
  writeln(ans);
end.