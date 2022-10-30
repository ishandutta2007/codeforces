program storm;
const nMax = 150;
var a:array[1..nMax] of longint;
    n,i,j,y,nom1,nom2,nom3:longint;


procedure inputdata;
var i:longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure outputdata(priz:longint);
begin
 if priz=0  then writeln(-1)
            else writeln(nom1,' ',nom2,' ',nom3);
end;

begin
 inputdata;
 nom1:=-1; nom2:=-1; nom3:=-1;
 for i:=1 to n do
  for j:=1 to n do
   for y:=1 to n do
    if (i<>j) and (i<>y) and (j<>y) and (a[i]=a[j]+a[y]) then
       begin
       nom1:=i; nom2:=j; nom3:=y;
       outputdata(1); halt;
       end;
 outputdata(0);
end.