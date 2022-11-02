var
  n:longint;
  w:array [1..60] of int64;
  l,r,ans:int64;
procedure init;
var
  i,j:longint;
begin
  read(n);
  w[1]:=1;
  for i:=2 to 60 do w[i]:=w[i-1]*2;
  for i:=1 to n do
  begin
    read(l,r);
    j:=1;
    while l<=r do
    begin
      ans:=l;
      while l and w[j]<>0 do inc(j);
      l:=l+w[j];
    end;
    writeln(ans);
  end;
end;
begin
  init;
end.