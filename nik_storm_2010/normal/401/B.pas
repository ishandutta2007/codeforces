var
  used:array[1..5000] of boolean;
  n,k,i,x,y,kind,k1,k2,j:longint;

begin
  readln(n,k);
  used[n]:=true;
  for i:=1 to k do
  begin
    read(kind);
    if (kind=1) then
    begin
      readln(x,y);
      used[x]:=true;
      used[y]:=true;
    end
    else
    begin
      readln(x);
      used[x]:=true;
    end;
  end;
  k1:=0;
  k2:=0;
  i:=1;
  while (i<n) do
  begin
    if (used[i]) then begin inc(i); continue; end;
    j:=i;
    while (j<n) and (not used[j]) do inc(j);
    x:=j-i;
    i:=j;
    k2:=k2+x;
    k1:=k1+(x+1) div 2;
  end;
  writeln(k1,' ',k2);
end.