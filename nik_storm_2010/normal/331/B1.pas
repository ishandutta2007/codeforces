uses math;
var
  tree:array[1..1200000] of longint; a,p:array[1..300000] of longint;
  n,m,i,x,y,z,w:longint;


procedure modify(i,l,r,d,w:longint);
var m:longint;
begin
  if (l=r) then tree[i]:=w else
  begin
    m:=(l+r) div 2;
    if (d<=m) then modify(i*2,l,m,d,w) else modify(i*2+1,m+1,r,d,w);
    tree[i]:=tree[i*2]+tree[i*2+1];
  end;
end;


function sum(i,l,r,ql,qr:longint):longint;
var m,res:longint;
begin
  if (l=ql) and (r=qr) then sum:=tree[i] else
  begin
    m:=(l+r) div 2; res:=0;
    if (ql<=m) then res:=res+sum(i*2,l,m,ql,min(qr,m));
    if (m<qr) then res:=res+sum(i*2+1,m+1,r,max(m+1,ql),qr);
    sum:=res;
  end;
end;


begin

  readln(n);
  for i:=1 to n do begin read(a[i]); p[a[i]]:=i; end;
  for i:=1 to n-1 do if p[i]>p[i+1] then modify(1,1,n,i,1);
  readln(m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    if x=1 then writeln(1+sum(1,1,n,y,z-1)) else
    begin
      p[a[y]]:=z; p[a[z]]:=y;
      w:=a[y]; a[y]:=a[z]; a[z]:=w;
      if (a[y]<>n) then begin if (p[a[y]]>p[a[y]+1]) then modify(1,1,n,a[y],1) else modify(1,1,n,a[y],0); end;
      if (a[y]<>1) then begin if (p[a[y]-1]>p[a[y]]) then modify(1,1,n,a[y]-1,1) else modify(1,1,n,a[y]-1,0); end;
      if (a[z]<>n) then begin if (p[a[z]]>p[a[z]+1]) then modify(1,1,n,a[z],1) else modify(1,1,n,a[z],0); end;
      if (a[z]<>1) then begin if (p[a[z]-1]>p[a[z]]) then modify(1,1,n,a[z]-1,1) else modify(1,1,n,a[z]-1,0); end;
    end;
  end;

end.