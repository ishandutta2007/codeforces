var
  a:array[0..100000] of longint;
  n,m,i:longint;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (a[i]<d) do inc(i);
    while (a[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

begin
  readln(n,m);
  for i:=1 to m do read(a[i]);
  randomize;
  if (m<>0) then sort(1,m);
  if (a[1]=1) or (a[m]=n) then begin writeln('NO'); halt; end;
  for i:=1 to m-2 do if (a[i]+1=a[i+1]) and (a[i+1]+1=a[i+2]) then
  begin
    writeln('NO');
    halt;
  end;
  writeln('YES');
end.