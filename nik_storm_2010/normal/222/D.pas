var
   a:array[1..2,1..100000] of longint; n,x,l,r,i,kol:longint;


procedure quicksort(nom,l,r:longint);
  var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[nom,random(r-l+1)+l];
  while i<=j do
    begin
      while a[nom,i]<d do inc(i);
      while a[nom,j]>d do dec(j);
      if i<=j then
        begin
          w:=a[nom,i]; a[nom,i]:=a[nom,j]; a[nom,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(nom,i,r);
  if l<j then quicksort(nom,l,j);
end;


begin

  readln(n,x); for i:=1 to n do read(a[1,i]);
  readln; for i:=1 to n do read(a[2,i]);
  randomize; quicksort(1,1,n); quicksort(2,1,n);

  r:=1; kol:=0;
  for l:=n downto 1 do
    begin
      while (r<=n) and (a[1,l]+a[2,r]<x) do inc(r);
      if r=n+1 then break;
      inc(kol); inc (r);
    end;
  writeln(1,' ',kol);

end.