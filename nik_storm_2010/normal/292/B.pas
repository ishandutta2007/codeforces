var
    kol:array[1..100000] of longint; n,m,i,a,b,k1,k2:longint;


begin

  readln(n,m);
  for i:=1 to m do
    begin
      readln(a,b); inc(kol[a]); inc(kol[b]);
    end;
  k1:=0; k2:=0;
  for i:=1 to n do
    begin
      if kol[i]=1 then inc(k1);
      if kol[i]=2 then inc(k2);
    end;
  if (k1=2) and (k2=n-2) then begin writeln('bus topology'); halt end;
  if (k2=n) then begin writeln('ring topology'); halt; end;
  if (k1=n-1) then begin writeln('star topology'); halt; end;
  writeln('unknown topology');

end.