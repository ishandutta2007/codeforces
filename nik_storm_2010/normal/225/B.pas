var
    mas,q:array[0..1000]of longint; kol,n,s,k,i,j,kk:longint;


begin

  readln(n,k); q[1]:=1; s:=1;
  while q[s]<=n do
    begin
      s:=s+1; kk:=k;
      for j:=s-1 downto 1 do
        begin
          q[s]:=q[s]+q[j]; kk:=kk-1;
          if kk=0 then break;
        end;
    end;

  s:=s-1;
  while n>0 do
    begin
      if q[s]<=n then
        begin
          n:=n-q[s]; inc(kol);
          mas[kol]:=q[s];
        end;
      s:=s-1;
    end;

  writeln(kol+1); write(0,' ');
  for i:=1 to kol do write(mas[i],' ');

end.