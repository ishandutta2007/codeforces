var
    used:array[1..1000] of longint; nom,kol,n,k,i,c:longint;


begin

  readln(n,k);
  for i:=1 to k do
    begin
      read(c);
      used[c]:=i;
    end;
  for nom:=1 to k do
    begin
      kol:=1;
      for i:=1 to n*k do
        if used[i]=nom then
          begin
            write(i,' ');
          end
            else
          begin
            if (kol<>n) and (used[i]=0) then
              begin
                used[i]:=nom; inc(kol);
                write(i,' ');
              end;
          end;
      writeln;
    end;

end.