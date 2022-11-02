var
n:longint;
k:longint;
i,j:longint;
a:array [1..10] of longint;
b:array [1..10,1..10] of longint;
c:array [1..50000] of string;
count:longint;
max,min:longint;
minsel:longint;

procedure permute(s:string;lev:longint);
var
  i:longint;
  temp:string;
begin
  if lev=k then
  begin
    count:=count+1;
    c[count]:=s;
  end
  else
  begin
    for i:=1 to k do
    begin
      str(i,temp);
      if pos(temp,s)=0 then
        permute(s+temp,lev+1);
    end;
  end;
end;

function cnt(s:String;x:longint):longint;
var
  i:longint;
  temp:longint;
begin
  temp:=0;
  for i:=1 to k do
  begin
    temp:=temp*10;
    temp:=temp+b[x][ord(s[i])-48];
  end;
  cnt:=temp;
end;




begin
readln(n,k);
minsel:=2000000000;
for i:=1 to n do
begin
  readln( a[i]);
  for j:=k downto 1 do
  begin
    b[i][j]:=a[i] mod 10;
    a[i]:=a[i] div 10;
  end;
end;
  permute('',0);
  for i:=1 to count do
  begin
    max:=0;
    min:=2000000000;
    for j:=1 to n do
    begin
      if cnt(c[i],j)>max then
        max:=cnt(c[i],j);
      if cnt(c[i],j)<min then
        min:=cnt(c[i],j);
    end;
    if(max-min<minsel) then
        minsel:=max-min;
  end;
  writeln(minsel);
end.