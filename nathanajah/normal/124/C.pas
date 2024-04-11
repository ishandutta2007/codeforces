var
a:array[1..1000] of boolean;
p:array[1..1000] of longint;
x:array[1..1000] of char;
countchar:array['a'..'z'] of longint;
count:longint;
counttotal:longint;
s:ansistring;
i,j:longint;
ic:char;
most:char;
temp:longint;
tempb:boolean;
max:longint;
charmax:char;
countx:longint;

begin
a[1]:=true;
i:=2;
while (i<=40) do
begin
 // writeln('i:',i);
  j:=i;
  while (i*j<=1000) do
  begin
    a[i*j]:=true;
    j:=j+1;
  end;
  i:=i+1;
  while (i<=40) and a[i] do
    i:=i+1;
end;
for i:=1 to 1000 do
  if not a[i] then
  begin
    count:=count+1;
    p[count]:=i;
  end;
//for i:=1 to count do
//  write(p[i],' ');
readln(s);
for i:=1 to length(s) do
  inc(countchar[s[i]]);
for ic:='a' to 'z' do
  if countchar[ic]>max then
  begin
    max:=countchar[ic];
    charmax:=ic;
  end;

temp:=length(s) div 2;
i:=count;
while (p[i]>temp) and (i>1) do
  dec(i);
temp:=i;
for i:=1 to length(s) do
begin
  tempb:=false;
  for j:=1 to temp do
    tempb:=tempb or (i mod p[j]=0);
  if tempb then
  begin
    x[i]:=charmax;
    inc(counttotal);
  end
  else
    x[i]:='_';
end;
if (counttotal>max) then
  writeln('NO')
else
begin
  j:=1;
  countx:=0;
  writeln('YES');
  for i:=1 to length(s) do
    if (x[i]='_') then
    begin
      while (s[j]=charmax) and (countx<counttotal) do
      begin
        inc(j);
        inc(countx);
      end;
      x[i]:=s[j];
      inc(j);
    end;
  for i:=1 to length(s) do
    write(x[i]);
  writeln;
end;




end.