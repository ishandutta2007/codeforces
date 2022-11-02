var
    simple:array[1..1000000] of byte; sq:extended;
      n,i:longint; tek:int64;


procedure sieve;
var i,j:int64;
begin
  i:=2; simple[1]:=1;
  while i<=1000000 do
    begin
      j:=i;
      while i*j<=1000000 do
        begin
          simple[i*j]:=1;
          inc(j);
        end;
      inc(i);
    end;
end;


begin

  readln(n); sieve;
  for i:=1 to n do
    begin
      read(tek); sq:=sqrt(tek);
      if frac(sq)<>0 then
        begin
          writeln('NO');
        end
          else
        begin
          if simple[trunc(sq)]=0 then
            begin
              writeln('YES');
            end
              else
            begin
              writeln('NO');
            end;
        end;
    end;

end.