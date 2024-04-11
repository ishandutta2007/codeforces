var
    a:array[1..100000] of longint; nom,n,d,i:longint; answer,leng:int64;


procedure dichotomy(c:longint; var nom:longint);
var l,m,r:longint;
begin
  l:=c; r:=n;
  while r-l>1 do
    begin
      m:=(r+l) div 2;
      if a[m]-a[c]>d then r:=m else l:=m;
    end;
  nom:=-1;
  if a[r]-a[c]<=d then nom:=r else if a[l]-a[c]<=d then nom:=l;
end;


begin

  readln(n,d); for i:=1 to n do read(a[i]);
  answer:=0;
  for i:=1 to n do
    begin
      dichotomy(i,nom);
      if nom-i>=2 then
        begin
          leng:=nom-i;
          answer:=answer+(leng*(leng-1)) div 2;
        end;
    end;
  writeln(answer);

end.