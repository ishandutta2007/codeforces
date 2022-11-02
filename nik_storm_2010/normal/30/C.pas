uses math;
var
  x,y,t,p,f:array[1..1000] of extended; n,i,j:longint; ans:extended;


procedure quicksort(l,r:longint);
var i,j:longint; d,w:extended;
begin
  i:=l; j:=r; d:=t[random(r-l+1)+l];
  while i<=j do
  begin
    while t[i]<d do inc(i);
    while t[j]>d do dec(j);
    if i<=j then
    begin
      w:=x[i]; x[i]:=x[j]; x[j]:=w;
      w:=y[i]; y[i]:=y[j]; y[j]:=w;
      w:=t[i]; t[i]:=t[j]; t[j]:=w;
      w:=p[i]; p[i]:=p[j]; p[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n); for i:=1 to n do readln(x[i],y[i],t[i],p[i]);
  randomize; quicksort(1,n);
  for i:=1 to n do
  begin
    f[i]:=p[i];
    for j:=i-1 downto 1 do
      if (f[j]+p[i]>f[i]) and (sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))+t[j]<=t[i]) then
      begin
        f[i]:=f[j]+p[i];
      end;
    ans:=max(f[i],ans);
  end;
  writeln(ans:0:6);

end.