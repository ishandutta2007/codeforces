const maxtime=1000000;
var
    t:array[1..1000000] of longint; maxkol,last,kol,n,i,a,b:longint;


begin

  readln(n);
  for i:=1 to n do
    begin
      readln(a,b); t[a]:=b;
    end;
  kol:=0; maxkol:=0;
  for i:=1 to maxtime  do
    begin
      if (kol<>0) then begin dec(kol); last:=i; end;
      if (t[i]<>0) then
        begin
          kol:=kol+t[i];
          if kol>maxkol then maxkol:=kol;
        end;
    end;
  if kol<>0 then last:=maxtime+kol;
  writeln(last,' ',maxkol);

end.