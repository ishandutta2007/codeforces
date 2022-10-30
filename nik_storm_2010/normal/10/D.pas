const
  lim=500;
var
  prev,path,a,b,f:array[0..lim] of longint;
  ans,n,m,i,j,nom:longint;
  p:boolean;

function check(x,y:longint):boolean;
var
  size,i,j:longint;
begin
  size:=f[y]+1;
  j:=x;
  for i:=size downto 1 do
  begin
    path[i]:=a[j];
    if (j=x) then j:=y else j:=prev[j];
  end;
  j:=1;
  for i:=1 to m do
  begin
    if (b[i]=path[j]) then inc(j);
    if (j>size) then exit(true);
  end;
  check:=false;
end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  read(m);
  for i:=1 to m do read(b[i]);
  for i:=1 to n do
  begin
    p:=false;
    for j:=1 to m do if (b[j]=a[i]) then p:=true;
    if (p=false) then continue;
    f[i]:=1;
    for j:=i-1 downto 1 do if (a[j]<a[i]) and (f[j]+1>f[i]) then
    begin
      p:=check(i,j);
      if (p=false) then continue;
      f[i]:=f[j]+1;
      prev[i]:=j;
    end;
  end;
  for i:=1 to n do if (f[i]>ans) then begin ans:=f[i]; nom:=i; end;
  j:=nom;
  for i:=ans downto 1 do
  begin
    path[i]:=a[j];
    j:=prev[j];
  end;
  writeln(ans);
  for i:=1 to ans do write(path[i],' ');
end.