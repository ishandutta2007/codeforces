const ma=1000000;
var
  n,m:longint;
  map:array [1..400,1..400] of longint;
function min(x,y:longint):longint;
begin
  if x<y then exit(x)
  else exit(y);
end;
procedure init;
var
  i,j,k:longint;
begin
  read(n,m);
  for i:=1 to n do
  for j:=1 to n do map[i,j]:=ma;
  for i:=1 to m do
  begin
    read(j,k);
    map[j,k]:=1;
    map[k,j]:=1;
  end;
  if map[1,n]=1 then
  begin
    for i:=1 to n do
    for j:=1 to n do
    if map[i,j]=1 then map[i,j]:=ma
    else map[i,j]:=1;
  end;
  for k:=1 to n do
  for i:=1 to n do
  for j:=1 to n do map[i,j]:=min(map[i,j],map[i,k]+map[k,j]);
  if map[1,n]=ma then writeln('-1')
  else writeln(map[1,n]);
end;
begin
  init;
end.