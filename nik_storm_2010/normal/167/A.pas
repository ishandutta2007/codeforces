uses math;
var
  prev,ans,a,d,t,v,x:extended; i,n:longint;


function find(v:extended):extended;
var t,s:extended;
begin
  t:=v/a; s:=a*t*t/2;
  if d>=s then find:=t+(d-s)/v else
  begin
    find:=sqrt(2*d/a);
  end;
end;


begin
  readln(n,a,d); prev:=0;
  for i:=1 to n do
  begin
    readln(t,v); x:=find(v);
    ans:=max(prev,x+t);
    prev:=ans;
    writeln(ans:0:4);
  end;
end.