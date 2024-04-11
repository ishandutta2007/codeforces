const module=1000000007;
var
    pro,x,y,n:int64;


function power(x,y:int64):int64;
var z:int64;
begin
  if y=0 then exit(1); if y=1 then exit(x);
  z:=power(x,y div 2);
  if y mod 2=1 then power:=(((z*z) mod module)*x) mod module else power:=(z*z) mod module;
end;



begin

  readln(n); if n=0 then begin writeln(1); halt; end;
  x:=power(2,n);
  if x=0 then x:=module-1 else x:=x-1;
  y:=power(2,n-1);
  pro:=(x*y) mod module;
  x:=power(4,n);
  if x<pro then x:=x+module;
  writeln(x-pro);

end.