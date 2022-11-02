var
  a,b,c,d,x,y:longint;


function gcd(x,y:longint):longint;
var res:longint;
begin
  if (y=0) then res:=x else res:=gcd(y,x mod y);
  exit(res);
end;


begin
  readln(a,b,c,d);
  if (a/b=c/d) then writeln('0/1') else
  begin
    if (a/b>c/d) then
    begin
      x:=a*d-b*c; y:=a*d;
      writeln(x div gcd(x,y),'/',y div gcd(x,y));
    end
      else
    begin
      x:=b*c-a*d; y:=b*c;
      writeln(x div gcd(x,y),'/',y div gcd(x,y));
    end;
  end;
end.