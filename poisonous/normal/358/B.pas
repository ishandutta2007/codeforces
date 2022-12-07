var a,g,h:string;
b,c,d,e,f:longint;
begin
readln(b);
for c:=1 to b do
begin
readln(g);
a:=a+'<3'+g;
end;
a:=a+'<3';
readln(g);
b:=1;
c:=1;
while  (b<=length(g)) and (c<=length(a))do
if g[b]=a[c] then begin
b:=b+1;
c:=c+1;
end else
b:=b+1;
//writeln(length(a));
if c>length(a) then writeln('yes') else
writeln('no');
end.