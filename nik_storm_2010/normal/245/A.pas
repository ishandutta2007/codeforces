var
    kola,kolb,suma,sumb,n,t,x,y,i:longint;


begin

  readln(n); kola:=0; suma:=0; kolb:=0; sumb:=0;
  for i:=1 to n do
    begin
      readln(t,x,y);
      if t=1 then
        begin
          inc(kola); suma:=suma+x;
        end
          else
        begin
          inc(kolb); sumb:=sumb+x;
        end;
    end;
  if suma>=(kola/2)*10 then writeln('LIVE') else writeln('DEAD');
  if sumb>=(kolb/2)*10 then writeln('LIVE') else writeln('DEAD');

end.