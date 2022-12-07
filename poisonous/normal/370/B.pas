type bo=array[1..100] of boolean;
function cmp(a,b:bo):boolean;
var z:longint;
begin
for z:=1 to 100 do
if a[z]<>b[z] then exit(false);
exit(true);
end;
function andd(a,b:bo):bo;
var z:bo;
y:longint;
begin
for y:=1 to 100 do
z[y]:=a[y] and b[y];
exit(z);
end;
var a,d,e,f,g,h,j,i,k,l:longint;
b:array[1..100] of boolean;
c:array[1..100] of bo;
begin
fillchar(b,sizeof(b),true);
fillchar(c,sizeof(c),false);
read(a);
for d:=1 to a do
begin
read(e);
for f:=1 to e do
begin
read(g);
c[d,g]:=true;
end;
end;
for d:=1 to a do
for f:=1 to a do
if d<>f then
if cmp(andd(c[d],c[f]),c[f]) then
b[d]:=false;
for d:=1 to a do
if b[d] then writeln('YES') else writeln('NO');
end.