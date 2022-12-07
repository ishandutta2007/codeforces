var a:array[1..4] of string;
h:array['1'..'9']of longint;
b,c,d,e,f,g:longint;
ch:char;
begin
readln(b);
for c:=1 to 4 do
readln(a[c]);
for c:=1 to 4 do
for d:=1 to 4 do
if(a[c,d]<='9')and(a[c,d]>='1') then
inc(h[a[c,d]]);
for ch:='1' to '9' do
if h[ch]>b*2 then begin
writeln('NO');
HALT;
END;
WRITELN('YES');
END.