var
    nom,n,k:int64;


function find(kol:int64):int64;
begin
  if kol=0 then exit(1); if kol=1 then exit(k);
  find:=(((k-1)+(k-kol))*(kol)) div 2 + 1;
end;


procedure dichotomy(var nom:int64);
var l,r,m:int64;
begin
  l:=0; r:=k-1;
  while r-l>1 do
    begin
      m:=(r+l) div 2;
      if find(m)>n then r:=m else l:=m;
    end;
  if find(l)>=n then nom:=l else
  if find(r)>=n then nom:=r else nom:=-1;
end;


begin

  readln(n,k);
  dichotomy(nom);
  writeln(nom);

end.