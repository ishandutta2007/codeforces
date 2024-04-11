var
    a,b:array[1..100000] of longint; n,i,kol:longint;


procedure quicksort(l,r:longint);
  var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[random(r-l+1)+l];
  while i<=j do
    begin
      while a[i]<d do inc(i);
      while a[j]>d do dec(j);
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

  readln(n); for i:=1 to n do read(a[i]); b:=a;
    randomize;  kol:=0;
  quicksort(1,n);

  for i:=1 to n do
    if a[i]<>b[i] then inc(kol);
  if (kol=0) or (kol=2) then writeln('YES') else writeln('NO');

end.