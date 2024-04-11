program storm;
var s:ansistring;
    d,i,kol1,kol2:longint;



procedure inputdata;
begin
 readln(s);
end;

procedure outputdata;
begin
 writeln(kol2*2);
end;

begin
 inputdata;
 d:=length(s);
 for i:=1 to d do
  if s[i]='(' then inc(kol1)
              else
                begin
                if (kol2+1)>kol1 then
                                 else inc(kol2);
                end;
 outputdata;
end.