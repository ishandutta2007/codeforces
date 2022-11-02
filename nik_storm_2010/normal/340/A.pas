var
  x,y,a,b,d,l:int64;


function gcd(a,b:longint):longint;
begin
  if (b=0) then exit(a);
  gcd:=gcd(b,a mod b);
end;


begin
  readln(x,y,a,b);
  d:=(x*y) div gcd(x,y);
  if (a mod d=0) then l:=a else l:=(a div d+1)*d;
  if (l>b) then writeln(0) else writeln((b-l) div d+1);
end.