const
  module=1000000007;
  l=3000;
var
  a:array[0..l,0..l] of char;
  f:array[0..l,0..l] of int64;
  x1,x2,x3,x4,ans:int64;
  i,j,n,m:longint;

function find(x1,y1,x2,y2:longint):int64;
var
  i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  for i:=x1 to x2 do for j:=y1 to y2 do
  begin
    if (a[i,j]='#') then continue;
    if (i=x1) and (j=y1) then f[i,j]:=1 else
    begin
      if (a[i-1,j]='.') then f[i,j]:=f[i,j]+f[i-1,j];
      if (a[i,j-1]='.') then f[i,j]:=f[i,j]+f[i,j-1];
      f[i,j]:=f[i,j] mod module;
    end;
  end;
  find:=f[x2,y2];
end;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  x1:=find(1,2,n-1,m);
  x2:=find(1,2,n,m-1);
  x3:=find(2,1,n-1,m);
  x4:=find(2,1,n,m-1);
  ans:=(x1*x4) mod module-(x2*x3) mod module;
  ans:=(ans+module) mod module;
  writeln(ans);
end.