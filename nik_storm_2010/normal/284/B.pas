var
    a:array[1..200000] of char; answer,kol,n,i:longint;



begin

  readln(n); kol:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]='I' then inc(kol);
    end;
  answer:=0;
  for i:=1 to n do
    begin
      if (a[i]='I') and (kol=1) then inc(answer);
      if (a[i]='A') and (kol=0) then inc(answer);
    end;
  writeln(answer);

end.