const base=1000000007;
var
    fact:array[0..1000000] of int64; ans,tek,a,b,n:int64; i:longint;


function check(c:int64):boolean;
var x:longint;
begin
  while c<>0 do
    begin
      x:=c mod 10; if (x<>a) and (x<>b) then exit(false);
      c:=c div 10;
    end;
  check:=true;
end;


function power(c,step:int64):int64;
var x:int64;
begin
  if step=1 then power:=c else
    begin
      x:=power(c,step div 2);
      if step mod 2=0 then power:=(x*x) mod base else power:=(((x*x) mod base)*c) mod base;
    end;
end;


begin

  readln(a,b,n); fact[0]:=1;
  for i:=1 to n do fact[i]:=(fact[i-1]*i) mod base;
  for i:=0 to n do
    if check(i*a+(n-i)*b) then
    begin
      tek:=(fact[i]*fact[n-i]) mod base;
      ans:=(ans+fact[n]*power(tek,base-2)) mod base;
    end;
  writeln(ans mod base);

end.