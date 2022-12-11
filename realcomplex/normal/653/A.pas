var
  n,i,j,k:longint;
  cur:longint;
  siz:array[1..50] of longint;
begin
  readln(n);
  for i:=1 to n do
    read(siz[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      for k:=j+1 to n do
      begin
        cur:=1;
        if(siz[i]=siz[j]) or (siz[j]=siz[k]) or (siz[i]=siz[k]) then
          cur:=0;
        if(siz[j]-siz[i]>2) or (siz[i]-siz[j]>2) or (siz[i]-siz[k]>2) or (siz[k]-siz[i]>2) or (siz[j]-siz[k]>2) or (siz[k]-siz[j]>2) then
          cur:=0;
        if cur=1 then
        begin
          writeln('YES');
          exit;
        end;
      end;
   writeln('NO');
end.