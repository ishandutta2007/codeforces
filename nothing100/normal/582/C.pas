var
  ans:int64;
  n:longint;
  a,g,ma,c:array [0..200000] of longint;
  bo:array [0..200000] of boolean;
function gcd(x,y:longint):longint;
begin
  if x mod y=0 then exit(y)
  else exit(gcd(y,x mod y));
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure init;
var
  i,j,l,o,k:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do g[i]:=gcd(i,n);
  for i:=1 to n-1 do
  if n mod i=0 then
  begin
    for j:=0 to i-1 do ma[j]:=0;
    for j:=1 to n do ma[j mod i]:=max(ma[j mod i],a[j]);
    for j:=1 to n do
    if a[j]=ma[j mod i] then bo[j]:=true
    else bo[j]:=false;
    l:=1;
    while (l<=n) and (bo[l]) do inc(l);
    for j:=1 to n do c[j]:=0;
    if l>n then for j:=1 to n do c[j]:=n
    else
    begin
      o:=0;
      for j:=1 to n do
      if (bo[(l+j-1) mod n+1]) then inc(o)
      else
      begin
        if o<>0 then
        begin
          for k:=1 to o do c[k]:=c[k]+o-k+1;
          o:=0;
        end;
      end;
    end;
    for j:=1 to n do if g[j]=i then ans:=ans+c[j];
  end;
  writeln(ans);
end;
begin
  init;
end.