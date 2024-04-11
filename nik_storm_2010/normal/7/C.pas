var
  a,b,c,x,y,nod:int64;


procedure gcd(a,b:int64;var x,y,nod:int64);
var xx,yy:int64;
begin
  if (b=0) then begin x:=1; y:=0; nod:=a; exit; end;
  gcd(b,a mod b,xx,yy,nod);
  x:=yy;
  y:=xx-trunc(a/b)*yy;
end;


begin
  readln(a,b,c);
  gcd(abs(a),abs(b),x,y,nod);
  if (c mod nod<>0) then writeln(-1) else
  begin
    x:=x*(-c div nod);
    y:=y*(-c div nod);
    if a<0 then x:=-x;
    if b<0 then y:=-y;
    writeln(x,' ',y);
  end;
end.