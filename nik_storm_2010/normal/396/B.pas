type
  fraction=record a,b:qword; end;
var
  res,n,x,y:qword;
  test,i:longint;
  d1,d2:fraction;

function gcd(x,y:qword):qword;
begin
  if (y=0) then begin gcd:=x; exit; end;
  gcd:=gcd(y,x mod y);
end;

function prime(x:qword):boolean;
var
  i:qword;
begin
  prime:=false; i:=2;
  while (i*i<=x) do
  begin
    if (x mod i=0) then exit;
    inc(i);
  end;
  prime:=true;
end;

function plus(a,b:fraction):fraction;
var
  x,y,z:qword;
begin
  z:=a.b div gcd(a.b,b.b)*b.b;
  x:=z div a.b*a.a;
  y:=z div b.b*b.a;
  x:=x+y;
  y:=gcd(x,z);
  plus.a:=x div y;
  plus.b:=z div y;
end;

function minus(a,b:fraction):fraction;
var
  x,y,z:qword;
begin
  z:=a.b div gcd(a.b,b.b)*b.b;
  x:=z div a.b*a.a;
  y:=z div b.b*b.a;
  x:=x-y;
  y:=gcd(x,z);
  minus.a:=x div y;
  minus.b:=z div y;
end;

begin
  readln(test);
  for i:=1 to test do
  begin
    readln(n);
    x:=n;
    while (not prime(x+1)) do dec(x);
    y:=n+1;
    while (not prime(y)) do inc(y);
    d1.a:=1; d1.b:=2;
    d2.a:=1; d2.b:=x+1;
    d1:=minus(d1,d2);
    d2.a:=n-x; d2.b:=(x+1)*y;
    d1:=plus(d1,d2);
    writeln(d1.a,'/',d1.b);
  end;
end.