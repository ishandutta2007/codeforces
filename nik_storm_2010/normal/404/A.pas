const
  lim=500;
var
  a:array[1..lim,1..lim] of char;
  used:array[1..lim,1..lim] of boolean;
  n,i,j:longint;
  x,y:char;

procedure print(s:string);
begin
  writeln(s);
  halt;
end;

begin
  readln(n);
  for i:=1 to n do for j:=1 to n do
  begin
    read(a[i,j]);
    if (j=n) then readln;
  end;
  x:=a[1,1];
  y:=a[1,2];
  if (x=y) then print('NO');
  for i:=1 to n do if (a[i,i]<>x) then print('NO') else used[i,i]:=true;
  for i:=1 to n do if (a[i,n-i+1]<>x) then print('NO') else used[i,n-i+1]:=true;
  for i:=1 to n do for j:=1 to n do
  begin
    if (used[i,j]) then continue;
    if (a[i,j]<>y) then print('NO');
  end;
  print('YES');
end.