uses
  math;
var
  nod,x,n,q,i:longint;

function gcd(a,b:longint):longint;
begin
  if (b=0) then exit(a);
  gcd:=gcd(b,a mod b);
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    read(x);
    nod:=gcd(nod,x);
    q:=max(q,x);
  end;
  if (odd(q div nod-n)) then writeln('Alice') else writeln('Bob');
end.