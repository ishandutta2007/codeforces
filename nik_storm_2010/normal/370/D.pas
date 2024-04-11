uses
  math;
const
  l=5000;
var
  a:array[0..l,0..l] of char;
  f:array[0..l,0..l] of longint;
  n,m,i,j,ans,x1,y1,x2,y2,sum,all,cur:longint;

procedure mode(x,y:longint); begin if (a[x,y]='.') then a[x,y]:='+'; end;
function line(x1,y1,x2,y2:longint):longint; begin exit(f[x2,y2]+f[x1-1,y1-1]-f[x2,y1-1]-f[x1-1,y2]); end;

function count(x1,y1,x2,y2:longint):longint;
var
  ans:longint;
begin
  if (x1=x2) and (y1=y2) then
  begin
    if (a[x1,y1]='w') then exit(1) else exit(0);
  end;
  ans:=line(x1,y1,x1,y2)+line(x1,y1,x2,y1)+line(x2,y1,x2,y2)+line(x1,y2,x2,y2);
  if (a[x1,y1]='w') then dec(ans);
  if (a[x1,y2]='w') then dec(ans);
  if (a[x2,y1]='w') then dec(ans);
  if (a[x2,y2]='w') then dec(ans);
  exit(ans);
end;

procedure print(x,y,dx,dy:longint);
var
  i,j,k:longint;
begin
  mode(x,y);
  for k:=1 to ans do
  begin
    mode(x+ans*dx,y+dy*k);
    mode(x,y+dy*k);
    mode(x+dx*k,y+dy*ans);
    mode(x+dx*k,y);
  end;
  for i:=1 to n do for j:=1 to m do
  begin
    write(a[i,j]);
    if (j=m) then writeln;
  end;
  halt;
end;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to n do for j:=1 to m do
  begin
    f[i,j]:=f[i-1,j]+f[i,j-1]-f[i-1,j-1];
    if (a[i,j]='w') then inc(f[i,j]);
  end;
  all:=f[n,m];
  ans:=maxlongint;
  x1:=-1; y1:=-1; x2:=-1; y2:=-1;
  for i:=1 to n do for j:=1 to m do if (a[i,j]<>'.') and (x1=-1) then x1:=i;
  for j:=1 to m do for i:=1 to n do if (a[i,j]<>'.') and (y1=-1) then y1:=j;
  for i:=n downto 1 do for j:=1 to m do if (a[i,j]<>'.') and (x2=-1) then x2:=i;
  for j:=m downto 1 do for i:=1 to n do if (a[i,j]<>'.') and (y2=-1) then y2:=j;
  cur:=maxlongint;
  for i:=1 to m do
  begin
    j:=i+x2-x1;
    if (j>m) then break;
    if count(x1,i,x2,j)=all then cur:=x2-x1;
  end;
  ans:=min(ans,cur);
  cur:=maxlongint;
  for i:=1 to n do
  begin
    j:=i+y2-y1;
    if (j>n) then break;
    if count(i,y1,j,y2)=all then cur:=y2-y1;
  end;
  ans:=min(ans,cur);
  if (ans=maxlongint) then begin writeln(-1); halt; end;
  for i:=1 to m do
  begin
    j:=i+x2-x1;
    if (j>m) then break;
    if (count(x1,i,x2,j)=all) and (x2-x1=ans) then print(x1,i,+1,+1);
  end;
  for i:=1 to n do
  begin
    j:=i+y2-y1;
    if (j>n) then break;
    if (count(i,y1,j,y2)=all) and (y2-y1=ans) then print(i,y1,+1,+1);
  end;
end.