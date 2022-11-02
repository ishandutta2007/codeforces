const ogr=2000000;
var
  used:array[1..ogr] of boolean; list:array[1..ogr] of longint;
  kol,i,j:int64; n,t:longint;


begin

  i:=2; kol:=0;
  while (i<=ogr) do
  begin
    if used[i]=false then
    begin
      j:=i*i; inc(kol); list[kol]:=i;
      while (j<=ogr) do begin used[j]:=true; j:=j+i; end;
    end;
    i:=i+1;
  end;
  readln(n);
  for t:=1 to n do write(list[t],' ');

end.