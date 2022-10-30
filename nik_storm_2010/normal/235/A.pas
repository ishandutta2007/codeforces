uses math;
var
    answer,i,j,n,x,y,z:int64;


function nod(a,b:int64):int64;
begin
  while (a>0) and (b>0) do
    if a>b then a:=a mod b else b:=b mod a;
  nod:=a+b;
end;


begin

  readln(n); answer:=0; x:=max(n-3,1);
  while x<=n do
    begin
      y:=max(n-3,1); while y<=n do
      begin
        z:=max(n-3,1); while z<=n do
        begin
          i:=nod(x,y); i:=(x*y) div i;
          j:=nod(i,z); j:=(i*z) div j;
          answer:=max(answer,j); inc(z);
        end;
        inc(y);
      end;
      inc(x);
    end;
  writeln(answer);

end.