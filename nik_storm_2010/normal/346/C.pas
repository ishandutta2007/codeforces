uses
  math;
var
  x:array[0..100000] of longint;
  ans,a,b,i,n,k,r,q:longint;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=x[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (x[i]<d) do inc(i);
    while (x[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=x[i]; x[i]:=x[j]; x[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

begin
  readln(n);
  for i:=1 to n do read(x[i]);
  readln(a,b);
  randomize;
  sort(1,n);
  for i:=1 to n do if (x[i]<>x[k]) then
  begin
    inc(k);
    x[k]:=x[i];
  end;
  while (a<>b) do
  begin
    if (k=0) then break;
    r:=a-1;
    i:=1;
    while (i<=k) do
    begin
      q:=a-a mod x[i];
      if (q>=b) then begin r:=min(r,q); inc(i); end
      else
      begin
        x[i]:=x[k];
        dec(k);
      end;
    end;
    a:=r;
    inc(ans);
  end;
  writeln(ans+a-b);
end.