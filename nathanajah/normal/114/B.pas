type permut=array[1..16] of integer;

var
n:longint;
m:longint;
i,j:longint;
s,s1,s2:string;
a:array[1..16] of string;
b:array[1..150] of longint;
c:array[1..150] of longint;
permutasi:array[1..100000] of permut;
count:longint;
kosong:permut;
max:longint;
permutmax:permut;
temp:longint;

procedure qsort;
  procedure sort(l,r:longint);
  var
    i, j:longint;
    x,y:string;
  begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    repeat
      while (a[i]<x) do
        inc(I);
      while (x<a[j]) do
        dec(j);
      if not(i>j) then
      begin
        y:=a[i];
        a[i]:=a[j];
        a[j]:=y;
        inc(i);
        dec(j);
      end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
begin
  sort(1,n);
end;

procedure permute(lev:longint;now:permut);
begin
  if lev=n then
  begin
    inc(count);
    permutasi[count]:=now;
  end
  else
  begin
    permute(lev+1,now);
    now[lev+1]:=1;
    permute(lev+1,now);
  end;
end;

function cocokkan(x:string):longint;
var
  i:longint;
begin
  for i:=1 to n do
    if x=a[i] then
      cocokkan:=i;
end;

//function hitungbanyak(x:permut):longint;
//var
//  i:longint;
//begin
//  hitungbanyak:=0;
//  for i:=1 to n do
//    if x[i]=1 then
//      hitungbanyak:=hitungbanyak+1;
//end;

function cek(x:permut):boolean;
var
  i:longint;
begin
  cek:=true;
  for i:=1 to m do
    if (x[b[i]]=1) and (x[c[i]]=1) then
      cek:=false;
end;
begin
  readln(n,m);
  for i:=1 to n do
    readln(a[i]);
  qsort;
  for i:=1 to m do
  begin
    readln(s1);
    s2:=copy(s1,pos(' ',s1)+1,length(s1)-pos(' ',s1));
    delete(s1,pos(' ',s1),length(S1)-pos(' ',s1)+1);
    b[i]:=cocokkan(s1);
    c[i]:=cocokkan(s2);
  end;
  permute(0,kosong);
(*  for i:=1 to count do
  begin
    for j:=1 to 8 do
      write(permutasi[i][j]);
    writeln;
  end;*)
  for i:=1 to count do
  begin
    temp:=0;
    for j:=1 to n do
      if permutasi[i][j]=1 then
        inc(temp);
    if (temp>max) and cek(permutasi[i]) then
    begin
      max:=temp;
      permutmax:=permutasi[i];
    end;
  end;
  writeln(max);
  for i:=1 to n do
    if permutmax[i]=1 then writeln(a[i]);
end.