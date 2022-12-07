var a,b,c,d,e,f:longint;
function max(a,b:longint):longint;
begin
if a>b then exit(a) else exit(b);
end;
begin
read(a,b,c,d);
if (a=c) and (b=d) then
begin
writeln('0 0 0');
halt;
end;
if(a=c) or (b=d) then write(1,' ') else write(2,' ');
if((a+c+b+d) mod 2<>0) then write(0,' ') else
if((c-d)=(a-b))or((c+d)=(a+b)) then write(1,' ') else
write(2,' ');
writeln(max(abs(a-c),abs(b-d)));
end.