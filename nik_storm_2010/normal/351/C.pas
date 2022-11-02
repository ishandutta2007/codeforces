uses
  math;
type
  massiv=array[0..50,0..50] of int64;
var
  f,x:massiv;
  a,b:array[0..50] of int64;
  n,m,i,j,k:longint;

function multi(a,b:massiv):massiv;
var
  i,j,k:longint;
  c:massiv;
begin
  for i:=0 to n do for j:=0 to n do c[i,j]:=maxlongint;
  for i:=0 to n do for j:=0 to n do for k:=0 to n do c[i,j]:=min(c[i,j],a[i,k]+b[k,j]);
  multi:=c;
end;

function step(a:massiv;c:longint):massiv;
var
  res:massiv;
begin
  if (c=1) then exit(a);
  res:=step(a,c div 2);
  res:=multi(res,res);
  if (odd(c)) then res:=multi(a,res);
  step:=res;
end;

begin
  readln(n,m);
  for i:=0 to n-1 do read(a[i]);
  for i:=0 to n-1 do read(b[i]);
  for i:=0 to n do for j:=0 to n do if (i=j) then f[i,j]:=0 else f[i,j]:=maxlongint;
  for i:=0 to n-1 do
  begin
    for j:=0 to n do for k:=0 to n do x[j,k]:=maxlongint;
    for j:=0 to n do for k:=0 to n do
    if (j+1=k) then x[j,k]:=a[i] else
    begin
      if (j-1=k) then x[j,k]:=b[i] else x[j,k]:=maxlongint;
    end;
    f:=multi(f,x);
  end;
  f:=step(f,m);
  writeln(f[0,0]);
end.