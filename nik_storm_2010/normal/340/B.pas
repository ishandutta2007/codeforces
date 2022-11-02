uses math;
var
  x,y:array[1..300] of longint; g:array[1..300,1..300] of extended;
  n,i,j,k:longint; ans,c1,c2,a,b,c:extended;


function sq(i,j,k:longint):extended;
var a,b,c,p:extended;
begin
  a:=g[i,j]; b:=g[i,k]; c:=g[j,k]; p:=(a+b+c)/2;
  sq:=p*(p-a)*(p-b)*(p-c);
end;


begin
  readln(n); for i:=1 to n do readln(x[i],y[i]);
  for i:=1 to n do for j:=1 to n do g[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
  for i:=1 to n do for j:=i+1 to n do
  begin
    a:=y[i]-y[j]; b:=x[j]-x[i]; c:=x[i]*y[j]-x[j]*y[i];
    c1:=-maxlongint; c2:=-maxlongint;
    for k:=1 to n do
    begin
      if (k=i) then continue;
      if (k=j) then continue;
      if (a*x[k]+b*y[k]+c>0) then c1:=max(c1,sq(i,j,k)) else c2:=max(c2,sq(i,j,k));
    end;
    if (c1=-maxlongint) or (c2=-maxlongint) then continue;
    ans:=max(ans,sqrt(c1)+sqrt(c2));
  end;
  writeln(ans:0:9);
end.