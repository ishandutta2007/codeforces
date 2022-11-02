var
  a,b:array[1..1000] of longint;
  n,m,i:longint;

function good(x:longint):boolean;
var
  i:longint;
  have:boolean;
begin
  for i:=1 to n do if (a[i]>x) then exit(false);
  have:=false;
  for i:=1 to n do if (a[i]*2<=x) then have:=true;
  if (have=false) then exit(false);
  for i:=1 to m do if (b[i]<=x) then exit(false);
  good:=true;
end;

begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  for i:=1 to 1000 do
  begin
    if (good(i)) then begin writeln(i); halt; end;
  end;
  writeln(-1);
end.