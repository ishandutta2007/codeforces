var
    b:array[1..2,1..100000] of longint; a:array[1..100000] of longint;
      nom,kol,x,y,n,m,i,j1,j2:longint;


procedure find(tek:longint; var nom:longint);
var l,r,m:longint;
begin
  l:=1; r:=kol;
  while r-l>1 do
    begin
      m:=(l+r) div 2;
      if b[1,m]<=tek then l:=m else r:=m;
    end;
  if (b[1,r]<=tek) then nom:=r else nom:=l;
end;


begin

  readln(n,m); for i:=1 to n do read(a[i]); readln;
  i:=1; kol:=0;
  while i<n do
    begin
      j1:=i+1; while (j1<=n) and (a[j1-1]<=a[j1]) do inc(j1);
      j2:=j1; while (j2<=n) and (a[j2-1]>=a[j2]) do inc(j2);
      inc(kol); b[1,kol]:=i; b[2,kol]:=j2-1;
      i:=j1;
    end;
  if n=1 then begin inc(kol); b[1,kol]:=1; b[2,kol]:=1; end;
  for i:=1 to m do
    begin
      readln(x,y); find(x,nom);
      if (b[1,nom]<=x) and (y<=b[2,nom]) then writeln('Yes') else writeln('No');
    end;

end.