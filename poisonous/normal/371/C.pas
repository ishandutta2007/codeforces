var a:string;
b,c,d:array[1..3] of longint;
e:longint;
f,g,h:INT64;
i,j,k,l,m,n:longint;
begin
readln(a);
for e:=1 to 3 do
read(b[e]);
for e:=1 to 3 do
read(c[e]);
read(f);
h:=maxlongint;
for e:=1 to length(a) do
if a[e]='B' then d[1]:=d[1]+1 else
if a[e]='S' then d[2]:=d[2]+1 else
if a[e]='C' then d[3]:=d[3]+1;
if (d[1]<>0) then
if(h>b[1] div d[1]) then h:=b[1] div d[1] else f:=f else b[1]:=0;
if (d[2]<>0) then
if(h>b[2] div d[2]) then h:=b[2] div d[2] else f:=f else b[2]:=0;
if (d[3]<>0) then
if(h>b[3] div d[3]) then h:=b[3] div d[3] else f:=f else b[3]:=0;
for e:=1 to 3 do
b[e]:=b[e]-h*d[e];
while(b[1]<>0)or (b[2]<>0) or (b[3]<>0) do
begin
for e:=1 to 3 do
if d[e]<>0 then
if b[e]<d[e] then
begin
f:=f-(d[e]-b[e])*c[e];
if f<0 then begin writeln(h); halt; end;
b[e]:=0;
end else b[e]:=b[e]-d[e];
h:=h+1;
end;
g:=0;
for e:=1 to 3 do
g:=g+(c[e]*d[e]);
h:=h+(f div g);
writeln(h);
end.