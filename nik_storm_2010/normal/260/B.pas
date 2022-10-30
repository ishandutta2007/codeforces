var
    mas:array[130000..151231] of longint; s,a:ansistring; yyyy,code,max,tek,dd,mm,d,i:longint;


begin

  readln(s); d:=length(s);
  for i:=1 to d-9 do
    if (s[i]<>'-') and (s[i+1]<>'-') and (s[i+2]='-') and (s[i+3]<>'-') and (s[i+4]<>'-') and
       (s[i+5]='-') and (s[i+6]<>'-') and (s[i+7]<>'-') and (s[i+8]<>'-') and (s[i+9]<>'-') then
        begin
          val(s[i]+s[i+1],dd,code); val(s[i+3]+s[i+4],mm,code);
          val(s[i+6]+s[i+7]+s[i+8]+s[i+9],yyyy,code);
          if ((yyyy=2013) or (yyyy=2014) or (yyyy=2015)) and (dd<>0) then
            begin
              if (mm=1) or (mm=3) or (mm=5) or (mm=7) or (mm=8) or (mm=10) or (mm=12) then
                begin
                  if dd<=31 then inc(mas[(yyyy mod 100)*10000+mm*100+dd]);
                end
                  else
                begin
                  if (mm=2) then
                    begin
                      if dd<=28 then inc(mas[(yyyy mod 100)*10000+mm*100+dd]);
                    end
                      else
                    begin
                      if (mm=4) or (mm=6) or (mm=9) or (mm=11) then
                        begin
                          if dd<=30 then inc(mas[(yyyy mod 100)*10000+mm*100+dd]);
                        end;
                    end;
                end;
            end;
        end;
  max:=0;
  for i:=130000 to 151231 do
    if mas[i]>max then
    begin
      max:=mas[i]; tek:=i;
    end;
  str(tek,a); writeln(a[5]+a[6],'-',a[3]+a[4],'-20',a[1]+a[2]);

end.