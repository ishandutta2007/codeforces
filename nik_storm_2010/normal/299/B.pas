var
    prev,n,k,i:longint; c:char;


begin

  readln(n,k); prev:=0;
  for i:=1 to n do
    begin
      read(c);
      if i-prev>k then begin writeln('NO'); halt; end;
      if c='.' then prev:=i;
    end;
  writeln('YES');

end.