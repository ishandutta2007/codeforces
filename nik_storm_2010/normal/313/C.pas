var
    a,f:array[0..2000000] of int64; n,i:longint; ans:int64;


procedure quicksort(l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[random(r-l+1)+l];
  while i<=j do
  begin
    while a[i]>d do inc(i);
    while a[j]<d do dec(j);
    if i<=j then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  randomize; quicksort(1,n);
  for i:=1 to n do f[i]:=f[i-1]+a[i];
  i:=1; ans:=0;
  while i<=n do
    begin
      ans:=ans+f[i]; i:=i*4;
    end;
  writeln(ans);

end.