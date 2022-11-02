const md=1000000009;
var
  res,l,n,m,k,x,y:int64;


function pow(x,y:int64):int64;
var c:int64;
begin
  if (y=1) then exit(x);
  c:=pow(x,y div 2);
  if (odd(y)) then pow:=(((c*c) mod md)*x) mod md else pow:=(c*c) mod md;
end;


begin
  readln(n,m,k); x:=n-m;
  if ((k-1)*(x+1)>=m) then res:=m else
  begin
    l:=m-(k-1)*x; y:=l div k;
    res:=((pow(2,y)-1)*k*2+m-y*k) mod md;
  end;
  writeln(res)
end.