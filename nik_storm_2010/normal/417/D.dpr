const
  l=100+5;
var
  f:array[0..1 shl 20] of int64;
  x,k,mask:array[0..l] of int64;
  n,m,b,h:int64;
  i,j,all,z:longint;

procedure up(var x:int64;y:int64);
begin
  if (x=-1) or (x>y) then x:=y;
end;

begin
  readln(n,m,b);
  for i:=1 to n do
  begin
    readln(x[i],k[i],all);
    for j:=1 to all do
    begin
      read(z);
      mask[i]:=mask[i] xor (1 shl (z-1));
    end;
  end;
  all:=(1 shl m)-1;
  for i:=1 to n do for j:=i+1 to n do if (k[i]<k[j]) then
  begin
    h:=x[i]; x[i]:=x[j]; x[j]:=h;
    h:=k[i]; k[i]:=k[j]; k[j]:=h;
    h:=mask[i]; mask[i]:=mask[j]; mask[j]:=h;
  end;
  for i:=1 to all do f[i]:=-1;
  for i:=1 to n do
  begin
    for j:=all downto 1 do if (f[j]<>-1) then up(f[j or mask[i]],f[j]+x[i]);
    up(f[mask[i]],x[i]+b*k[i]);
  end;
  writeln(f[all]);
end.