var
  a,b:array[1..500] of longint;
  ans,n,i,j,w,l,r,m:longint;

function min(x,y:longint):longint; begin if (x<y) then exit(x) else exit(y); end;

function may(x:longint):boolean;
var
  i,k,j:longint;
begin
  for i:=1 to x do b[i]:=maxlongint;
  j:=1;
  for i:=n downto 1 do
  begin
    k:=0;
    while (b[j]=0) and (k<=n) do
    begin
      inc(j);
      if (j>x) then j:=1;
      inc(k);
    end;
    if (k>n) then exit(false);
    b[j]:=min(a[i],b[j]-1);
    inc(j);
    if (j>x) then j:=1;
  end;
  exit(true);
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do for j:=i+1 to n do if (a[i]>a[j]) then begin w:=a[i]; a[i]:=a[j]; a[j]:=w; end;
  ans:=0;
  l:=0; r:=n;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (may(m)) then r:=m else l:=m;
  end;
  writeln(r);
end.