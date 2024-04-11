program storm;
var kol,n:longint;


procedure inputdata;
var i,code,chiclo:longint;
    s:string;
begin
 readln(n);
 for i:=1 to n do
  begin
  readln(s);
  val(s,chiclo,code);
  if code=0 then
     begin
      if chiclo<=17 then inc(kol);
     end
            else
     begin
      if (s='ABSINTH') or (s='BEER') or (s='BRANDY') or (s='CHAMPAGNE') or
          (s='GIN') or (s='RUM') or (s='SAKE') or (s='TEQUILA') or (s='VODKA') or
           (s='WHISKEY') or (s='WINE') then inc(kol);
     end;
  end;
end;

procedure outputdata;
begin
 writeln(kol);
end;

begin
 inputdata;
 outputdata;
end.