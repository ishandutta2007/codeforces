uses
  math;
const
  ll=510;
var
  a,s:array[0..ll,0..ll] of int64;
  q,u,q1,u1:array[1..ll,1..ll] of int64;
  move,need:array[0..ll] of int64;
  n,m,r,i,j,il,ir,jl,jr,z1,z2,x,y:longint;
  ans,cnt:int64;

function dst(x1,y1,x2,y2:longint):extended;
begin
  dst:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
end;

function good(x,y:longint):boolean;
var
  i,j:longint;
begin
  for i:=1 to n do for j:=1 to m do
  if (dst(1,1,i,j)<=r) and (dst(x,y,i,j)<=r) then exit(false);
  good:=true;
end;

procedure findsum;
var
  ma,cn,i,j,x,y,k,sum:longint;
begin
  il:=r+1; ir:=n-r;
  jl:=r+1; jr:=m-r;
  for i:=0 to r do for j:=0 to r do if (sqrt(i*i+j*j)<=r) then move[i]:=j;
  x:=il;
  y:=jl;
  sum:=0;
  for i:=1 to 2*r+1 do for j:=1 to 2*r+1 do if (sqrt((i-x)*(i-x)+(j-y)*(j-y))<=r) then sum:=sum+a[i,j];
  j:=m;
  for i:=0 to 2*r do
  begin
    while (j>=1) and (good(i+1,j)) do dec(j);
    if (j<>m) then inc(j);
    need[i]:=j-1;
  end;
  for x:=il to ir do
  begin
    if (x<>il) then
    begin
      y:=jl;
      sum:=s[x-1,y];
      for k:=0 to r do
      begin
        sum:=sum-a[x-move[k]-1,y-k]-a[x-move[k]-1,y+k];
        sum:=sum+a[x+move[k],y+k]+a[x+move[k],y-k];
      end;
      sum:=sum+a[x-r-1,y]-a[x+r,y];
    end;
    for y:=jl to jr do
    begin
      if (y=jl) then begin s[x,y]:=sum; continue; end;
      for k:=0 to r do sum:=sum-a[x-k,y-move[k]-1]-a[x+k,y-move[k]-1]+a[x+k,y+move[k]]+a[x-k,y+move[k]];
      sum:=sum+a[x,y-r-1]-a[x,y+r];
      s[x,y]:=sum;
    end;
  end;
  for i:=1 to n do for j:=1 to m do
  begin
    ma:=-maxlongint;
    for k:=m downto j do
    begin
      if (s[i,k]=ma) then inc(cn);
      if (s[i,k]>ma) then
      begin
        ma:=s[i,k];
        cn:=1;
      end;
    end;
    q[i,j]:=ma;
    u[i,j]:=cn;
  end;
  for i:=1 to n do for j:=1 to m do
  begin
    ma:=-maxlongint;
    for k:=1 to j do
    begin
      if (s[i,k]=ma) then inc(cn);
      if (s[i,k]>ma) then
      begin
        ma:=s[i,k];
        cn:=1;
      end;
    end;
    q1[i,j]:=ma;
    u1[i,j]:=cn;
  end;
end;

begin
  readln(n,m,r);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to n do for j:=1 to m do s[i,j]:=-1;
  findsum;
  ans:=0;
  cnt:=0;
  for x:=il to ir do for y:=jl to jr do
  begin
    for i:=x+1 to min(ir,x+2*r) do
    begin
      if (y+need[i-x]<=m) then
      begin
        z1:=q[i,y+need[i-x]];
        z2:=u[i,y+need[i-x]];
        if (z1<>-1) then
        begin
          if (s[x,y]+z1=ans) then cnt:=cnt+z2;
          if (s[x,y]+z1>ans) then
          begin
            ans:=s[x,y]+z1;
            cnt:=z2;
          end;
        end;
      end;
      if (y-need[i-x]>=1) then
      begin
        z1:=q1[i,y-need[i-x]];
        z2:=u1[i,y-need[i-x]];
        if (z1<>-1) then
        begin
          if (s[x,y]+z1=ans) then cnt:=cnt+z2;
          if (s[x,y]+z1>ans) then
          begin
            ans:=s[x,y]+z1;
            cnt:=z2;
          end;
        end;
      end;
    end;
    if (y+need[0]<=m) then
    begin
      z1:=q[x,y+need[0]];
      z2:=u[x,y+need[0]];
      if (z1<>-1) then
      begin
        if (s[x,y]+z1=ans) then cnt:=cnt+z2;
        if (s[x,y]+z1>ans) then
        begin
          ans:=s[x,y]+z1;
          cnt:=z2;
        end;
      end;
    end;
    for i:=(x+2*r+1) to ir do
    begin
      z1:=q[i,1];
      z2:=u[i,1];
      if (z1<>-1) then
      begin
        if (s[x,y]+z1=ans) then cnt:=cnt+z2;
        if (s[x,y]+z1>ans) then
        begin
          ans:=s[x,y]+z1;
          cnt:=z2;
        end;
      end;
    end;
  end;
  writeln(ans,' ',cnt);
end.