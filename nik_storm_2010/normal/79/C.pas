uses math;
var
  w:array[1..10] of string; ll:array[1..10] of longint; ans,ps,n,x,d,i,l,r:longint;
  s:ansistring;


function check(l,r:longint):longint;
var i,res:longint;
begin
  res:=-1;
  for i:=1 to n do
  begin
    if (r-l+1<ll[i]) then continue;
    if (copy(s,r-ll[i]+1,ll[i])=w[i]) then res:=max(res,r-ll[i]+1);
  end;
  check:=res;
end;


begin
  readln(s); d:=length(s);
  readln(n);
  for i:=1 to n do
  begin
    readln(w[i]);
    ll[i]:=length(w[i]);
  end;
  l:=1;
  for r:=1 to d do
  begin
    x:=check(l,r);
    if (x=-1)
    then begin if (ans<r-l+1) then begin ans:=r-l+1; ps:=l-1; end; end
    else l:=x+1;
  end;
  writeln(ans,' ',ps);
end.