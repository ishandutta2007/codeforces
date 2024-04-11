var
  a:array[1..2000] of longint;
  ans,n,k1,k2,i,j:longint;

function find(x:longint):longint;
var
  res,i:longint;
begin
  res:=0;
  for i:=1 to x-1 do if (a[i]>a[x]) then inc(res);
  for i:=x+1 to n do if (a[x]>a[i]) then inc(res);
  find:=res;
end;

begin
  readln(n);
  for i:=1 to n do begin read(a[i]); a[i]:=abs(a[i]); end;
  for i:=1 to n do
  begin
    k1:=find(i);
    a[i]:=-a[i];
    k2:=find(i);
    if (k1<=k2) then a[i]:=-a[i];
  end;
  ans:=0;
  for i:=1 to n do for j:=i+1 to n do if (a[i]>a[j]) then inc(ans);
  writeln(ans);
end.