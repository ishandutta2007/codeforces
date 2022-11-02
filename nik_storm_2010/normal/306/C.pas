const module=1000000009; maxn=4000;
var
    c:array[0..maxn,0..maxn] of int64; fact:array[0..maxn] of int64;
      tek,kol1,kol2,ans,ost,inv1,inv2,n,w,b:int64; i,j:longint;



begin

  readln(n,w,b); fact[0]:=1;
  for i:=0 to maxn do c[i,0]:=1;
  for i:=1 to maxn do
    for j:=1 to maxn do
    if i<j then c[i,j]:=0 else c[i,j]:=(c[i-1,j-1]+c[i-1,j]) mod module;
  for i:=1 to maxn do fact[i]:=(fact[i-1]*i) mod module;
  ans:=0;
  for i:=1 to w-1 do
    for j:=1 to b do
    if i+j>n then break else
    begin
      ost:=n-i-j; if (ost=0) or (i+ost>w) then continue;
      kol1:=(fact[w]*c[w-1,i+ost-1]) mod module;
      kol2:=(fact[b]*c[b-1,j-1]) mod module;
      ans:=(ans+kol1*kol2) mod module;
    end;
  writeln(ans);

end.