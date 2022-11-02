var
    a:array[1..2,0..101000] of longint; b,c:array[0..101000] of longint; kol,n,i:longint;


procedure quicksort(l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[1,random(r-l+1)+l];
  while i<=j do
    begin
      while a[1,i]<d do inc(i);
      while a[1,j]>d do dec(j);
      if i<=j then
        begin
          w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
          w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n); randomize;
  for i:=1 to n do
    begin
      read(a[1,i]); a[2,i]:=i;
    end;
  quicksort(1,n); kol:=(n+2) div 3;
  for i:=1 to kol do begin b[a[2,i]]:=a[1,i]; c[a[2,i]]:=0; end;
  for i:=kol+1 to 2*kol do begin b[a[2,i]]:=0; c[a[2,i]]:=a[1,i]; end;
  for i:=n downto 2*kol+1 do
    begin
      c[a[2,i]]:=n-i+1;
      b[a[2,i]]:=a[1,i]-c[a[2,i]];
    end;
  writeln('YES'); for i:=1 to n do write(b[i],' ');
  writeln; for i:=1 to n do write(c[i],' ');

end.