var
    mas:array[0..100000] of longint; tek,a,b,m,r:longint;


begin

  readln(a,b,m,r);
  while true do
    begin
      r:=(a*r+b) mod m; inc(tek);
      if mas[r]=0 then
        begin
          mas[r]:=tek;
        end
          else
        begin
          break;
        end;
    end;
  writeln(tek-mas[r]);

end.