const md=1000000007; ll=2000;
var
  c:array[0..ll,0..ll] of int64; used:array[-1..ll] of boolean;
  a,f:array[0..ll] of int64; ans,x,n,k,l:int64; i,j:longint;


begin
  readln(n);
  for i:=1 to n do begin read(a[i]); used[a[i]]:=true; end;
  f[0]:=1; for i:=1 to n do f[i]:=(f[i-1]*i) mod md;
  for i:=1 to n do
  begin
    if (a[i]=-1) then inc(k) else continue;
    if (not used[i]) then inc(l);
  end;
  ans:=f[k];
  for i:=0 to n do c[i,0]:=1;
  for i:=1 to n do for j:=1 to n do c[i,j]:=(c[i-1,j]+c[i-1,j-1]) mod md;
  for i:=1 to l do
  begin
    x:=(c[l,i]*f[k-i]) mod md;
    if (odd(i)) then ans:=ans-x else ans:=ans+x;
    if (ans<0) then ans:=ans+md;
    if (ans>=md) then ans:=ans-md;
  end;
  writeln(ans);
end.