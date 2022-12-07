var a,b,c,e,f:qword;d:longint;
c10:array[0..19] of qword;
function len(g:qword):longint;
var x:longint;
begin
x:=0;
while(g>0) do
begin
x:=x+1;
g:=g div 10;
end;
exit(x);
end;
begin
f:=0;
read(a,b,c);
c10[0]:=1;
for d:=1 to 19 do
c10[d]:=c10[d-1]*10;
while(a>0) do
begin
e:=len(b);
if(a div (c10[e]-b) div e>=c) then
begin
a:=a-(c10[e]-b)*c*e;
f:=f+(c10[e]-b);
b:=c10[e];
end else
begin
f:=f+a div c div e;
a:=0;
end;
end;
writeln(f);
end.