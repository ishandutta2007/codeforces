uses math; const module = 1000000007;
var
    tree:array[1..4000000] of int64; a,f:array[1..1000000] of int64;
      ans,cur:int64; n,i:longint;


procedure modify(i,l,r,d,w:int64);
var m:int64;
begin
  if (l=r) then tree[i]:=w else
  begin
    m:=(l+r) div 2;
    if d<=m then modify(i*2,l,m,d,w) else modify(i*2+1,m+1,r,d,w);
    tree[i]:=tree[i*2]+tree[i*2+1];
  end;
end;


function sum(i,l,r,ql,qr:int64):int64;
var res,m:int64;
begin
  if (l=ql) and (r=qr) then res:=tree[i] else
  begin
    m:=(l+r) div 2; res:=0;
    if ql<=m then res:=res+sum(i*2,l,m,ql,min(qr,m));
    if m<qr then res:=res+sum(i*2+1,m+1,r,max(ql,m+1),qr);
  end;
  sum:=res mod module;
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  for i:=1 to n do
    begin
      cur:=(sum(1,1,1000000,1,a[i])*a[i]+a[i]) mod module;
      modify(1,1,1000000,a[i],cur); f[a[i]]:=cur;
    end;
  ans:=0;
  for i:=1 to 1000000 do ans:=(ans+f[i]) mod module;
  writeln(ans);

end.