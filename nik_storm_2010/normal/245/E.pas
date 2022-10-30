uses math;
var
    s:ansistring; answ,kolp,kolm,d,i:longint;


begin

  readln(s); d:=length(s); answ:=0;
  for i:=1 to d do
    begin
      if s[i]='-' then
        begin
          if kolp<>0 then begin dec(kolp); inc(kolm); end
                     else begin inc(kolm); inc(answ); end;
        end
          else
        begin
          if kolm<>0 then begin dec(kolm); inc(kolp); end
                     else begin inc(kolp); inc(answ); end;
        end;
    end;
  writeln(answ);

end.