var a,b,c,d,e,f:longint;
g:array[1..100] of longint;
h:array[0..100,1..2] of longint;
function min(a,b:longint):longint;
begin
if a>b then exit(a) else exit(b);
end;
begin
read(a,f);
for b:=1 to a do
read(g[b]);
for b:=1 to a do
h[b mod f,g[b]]:=h[b mod f,g[b]]+1;
c:=0;
for b:=0 to f-1 do
c:=c+(a div f)-min(h[b,1],h[b,2]);
writeln(c);
end.