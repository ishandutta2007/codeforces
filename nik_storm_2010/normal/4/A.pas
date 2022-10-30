program storm;
var w,ch1,ch2:longint;

procedure inputdata;
begin
 readln(w);
end;

procedure outputdata(priz:longint);
begin
 if priz=1        then writeln('YES')
                  else writeln('NO');
end;

begin
 inputdata;
 ch1:=2;
 while ch1<w do
  begin
  ch2:=w-ch1;
  if (ch1<>0) and (ch1 mod 2 = 0) and (ch2<>0) and (ch2 mod 2 = 0) then
    begin outputdata(1); halt; end;
  ch1:=ch1+2;
  end;
 outputdata(0);
end.