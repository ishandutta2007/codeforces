const module=1000000007;
type mat=array[1..52,1..52] of int64;
var
  g:mat; m,k,i,j,x,y:longint; ans,n:int64; c:char;


function multi(a,b:mat):mat;
var i,j,k:longint; c:mat;
begin
  for i:=1 to m do for j:=1 to m do
  begin
    c[i,j]:=0;
    for k:=1 to m do c[i,j]:=(c[i,j]+a[i,k]*b[k,j]) mod module;
  end;
  multi:=c;
end;


function power(c:mat;x:int64):mat;
var w:mat;
begin
  if (x=1) then exit(c);
  w:=power(c,x shr 1);
  if (odd(x)) then power:=multi(c,multi(w,w)) else power:=multi(w,w);
end;


begin
  readln(n,m,k);
  for i:=1 to m do for j:=1 to m do g[i,j]:=1;
  for i:=1 to k do
  begin
    read(c); if (97<=ord(c)) and (ord(c)<=122) then x:=ord(c)-96 else x:=ord(c)-38;
    readln(c); if (97<=ord(c)) and (ord(c)<=122) then y:=ord(c)-96 else y:=ord(c)-38;
    g[x,y]:=0;
  end;
  if (n=1) then ans:=m else
  begin
    g:=power(g,n-1);
    for i:=1 to m do for j:=1 to m do ans:=(ans+g[i,j]) mod module;
  end;
  writeln(ans);
end.