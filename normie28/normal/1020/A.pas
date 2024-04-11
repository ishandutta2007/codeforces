var n,h,a,b,k,i,ver,hor:longint;
ta,fa,tb,fb:array[1..10000] of longint;
begin
readln(n,h,a,b,k);
for i:=1 to k do readln(ta[i],fa[i],tb[i],fb[i]);
for i:=1 to k do 
begin
ver:=abs(fa[i]-fb[i]);
hor:=abs(ta[i]-tb[i]);
if hor=0 then writeln(ver)
else if (fa[i]>b) and (fb[i]>b) then writeln(fa[i]-b+fb[i]-b+hor)
else if (fa[i]<a) and (fb[i]<a) then writeln(a-fa[i]+a-fb[i]+hor)
else writeln(ver+hor);
end;
end.