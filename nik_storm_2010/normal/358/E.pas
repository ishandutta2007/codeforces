const
  ll=1000+10;
var
  a,v,g:array[0..ll,0..ll] of longint;
  q:array[1..2,1..ll*ll] of longint;
  used:array[0..ll,0..ll] of boolean;
  n,m,i,j,xx,yy,max,l,sum,st,en:longint;
  good,maybe:boolean;

function solve(leng:longint):boolean;
var
  i,j,cnt,vv,ss,x,y,step:longint;
begin
  x:=xx;
  y:=yy;
  while (x-leng>0) do x:=x-leng;
  while (y-leng>0) do y:=y-leng;
  cnt:=0;
  vv:=0;
  ss:=0;
  i:=x;
  while (i<=n) do
  begin
    j:=y;
    while (j<=m) do
    begin
      if (a[i,j]<>1) then begin j:=j+leng; continue; end;
      inc(vv);
      step:=0;
      if (i-leng>-0) and (a[i-leng,j]=1) and (v[j,i]-v[j,i-leng-1]=leng+1) then begin inc(step); ss:=ss+v[j,i]-v[j,i-leng-1]-2; end;
      if (i+leng<=n) and (a[i+leng,j]=1) and (v[j,i+leng]-v[j,i-1]=leng+1) then begin inc(step); ss:=ss+v[j,i+leng]-v[j,i-1]-2; end;
      if (j-leng>-0) and (a[i,j-leng]=1) and (g[i,j]-g[i,j-leng-1]=leng+1) then begin inc(step); ss:=ss+g[i,j]-g[i,j-leng-1]-2; end;
      if (j+leng<=m) and (a[i,j+leng]=1) and (g[i,j+leng]-g[i,j-1]=leng+1) then begin inc(step); ss:=ss+g[i,j+leng]-g[i,j-1]-2; end;
      if (odd(step)) then inc(cnt);
      j:=j+leng;
    end;
    i:=i+leng;
  end;
  if (ss div 2+vv<>sum) then exit(false);
  if (cnt>2) then exit(false);
  solve:=true;
end;

procedure add(i,j:longint);
begin
  q[1,en]:=i;
  q[2,en]:=j;
  used[i,j]:=true;
  inc(en);
end;

function bfs:boolean;
var
  i,j:longint;
begin
  st:=1;
  en:=1;
  add(xx,yy);
  q[1,1]:=xx;
  q[2,1]:=yy;
  while (st<>en) do
  begin
    i:=q[1,st];
    j:=q[2,st];
    inc(st);
    if (a[i-1,j]=1) and (not used[i-1,j]) then add(i-1,j);
    if (a[i+1,j]=1) and (not used[i+1,j]) then add(i+1,j);
    if (a[i,j-1]=1) and (not used[i,j-1]) then add(i,j-1);
    if (a[i,j+1]=1) and (not used[i,j+1]) then add(i,j+1);
  end;
  for i:=1 to n do for j:=1 to m do if (a[i,j]=1) and (not used[i,j]) then exit(false);
  bfs:=true;
end;

begin
  readln(n,m);
  xx:=-1;
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(a[i,j]);
      if (a[i,j]=1) and (xx=-1) then begin xx:=i; yy:=j; end;
      sum:=sum+a[i,j];
    end;
    readln;
  end;
  for i:=1 to n do for j:=1 to m do g[i,j]:=g[i,j-1]+a[i,j];
  for j:=1 to m do for i:=1 to n do v[j,i]:=v[j,i-1]+a[i,j];
  max:=0;
  for i:=1 to n do
  begin
    j:=1;
    while (true) do
    begin
      l:=0;
      while (j<=m) and (a[i,j]=1) do begin inc(l); inc(j); end;
      if (max<l) then max:=l;
      inc(j);
      if (j>m) then break;
    end;
  end;
  for i:=1 to m do
  begin
    j:=1;
    while (true) do
    begin
      l:=0;
      while (j<=n) and (a[j,i]=1) do begin inc(l); inc(j); end;
      if (max<l) then max:=l;
      inc(j);
      if (j>n) then break;
    end;
  end;
  dec(max);
  if (max<=1) or (bfs=false) then begin writeln(-1); halt; end;
  good:=false;
  for i:=2 to max do
  begin
    if (max mod i<>0) then continue;
    maybe:=solve(i);
    if (maybe) then
    begin
      good:=true;
      write(i,' ');
    end;
  end;
  if (not good) then begin writeln(-1); halt; end;
end.