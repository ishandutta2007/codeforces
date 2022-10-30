var
    ans,n,m:int64;


function power(c,step:int64):int64;
var res,x:int64;
begin
  if step=1 then res:=c else
    begin
      x:=power(c,step div 2);
      if step mod 2=1 then res:=(x*x) mod m * c else res:=x*x;
    end;
  exit(res mod m);
end;


begin

  readln(n,m); ans:=power(3,n);
  if ans=0 then writeln(m-1) else writeln(ans-1);

end.