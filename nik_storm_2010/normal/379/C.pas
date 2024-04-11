var
  a,b,c:array[1..500000] of longint;
  n,i,now:longint;

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
      w:=b[i]; b[i]:=b[j]; b[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

begin
  readln(n);
  for i:=1 to n do begin read(a[i]); b[i]:=i; end;
  randomize;
  sort(1,n);
  now:=0;
  for i:=1 to n do
  begin
    if (a[i]>now)
    then begin c[b[i]]:=a[i]; now:=a[i]; end
    else
    begin
      inc(now);
      c[b[i]]:=now;
    end;
  end;
  for i:=1 to n do write(c[i],' ');
end.