uses
  math;
const
  lim=300000;
  oo=1000000000;
type
  edges=record
    t,n:longint;
  end;
var
  ee:array[1..2*lim] of edges;
  a,start,l1,r1,l0,r0,ps,depth:array[1..2*lim] of longint;
  tree,add:array[0..1,0..4*lim] of int64;
  used:array[1..2*lim] of boolean;
  n,m,i,cnt,time,kind:longint;
  z,x,y:int64;

procedure addedges(x,y:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  start[x]:=cnt;
end;

procedure dfs(nom,dp:longint);
var
  e,too,o:longint;
begin
  inc(time);
  ps[nom]:=time;
  used[nom]:=true;
  o:=ps[nom];
  depth[o]:=dp;
  e:=start[nom];
  while (e<>0) do
  begin
    too:=ee[e].t;
    if (used[too]=false) then
    begin
      dfs(too,dp+1);
      l0[o]:=min(l0[o],l0[ps[too]]);
      r0[o]:=max(r0[o],r0[ps[too]]);
      l1[o]:=min(l1[o],l1[ps[too]]);
      r1[o]:=max(r1[o],r1[ps[too]]);
    end;
    e:=ee[e].n;
  end;
  if (dp mod 2=0) then
  begin
    l0[o]:=min(l0[o],o);
    r0[o]:=max(r0[o],o);
  end
  else
  begin
    l1[o]:=min(l1[o],o);
    r1[o]:=max(r1[o],o);
  end;
end;

procedure push(nom,i,l,r:longint);
var
  m:longint;
begin
  m:=(l+r) div 2;
  tree[nom,i*2]:=tree[nom,i*2]+add[nom,i]*(m-l+1);
  add[nom,i*2]:=add[nom,i*2]+add[nom,i];
  tree[nom,i*2+1]:=tree[nom,i*2+1]+add[nom,i]*(r-m);
  add[nom,i*2+1]:=add[nom,i*2+1]+add[nom,i];
  add[nom,i]:=0;
end;

procedure modify(nom,i,l,r,ql,qr:longint;x:int64);
var
  m:longint;
begin
  if (ql=l) and (qr=r) then
  begin
    tree[nom,i]:=tree[nom,i]+(r-l+1)*x;
    add[nom,i]:=add[nom,i]+x;
    exit;
  end;
  push(nom,i,l,r);
  m:=(l+r) div 2;
  if (ql<=m) then modify(nom,i*2,l,m,ql,min(m,qr),x);
  if (m<qr) then modify(nom,i*2+1,m+1,r,max(m+1,ql),qr,x);
  tree[nom,i]:=tree[nom,i*2]+tree[nom,i*2+1];
end;

function sum(nom,i,l,r,x:longint):int64;
var
  m:longint;
begin
  if (l=r) then exit(tree[nom,i]);
  push(nom,i,l,r);
  m:=(l+r) div 2;
  if (x<=m) then exit(sum(nom,i*2,l,m,x)) else exit(sum(nom,i*2+1,m+1,r,x));
end;

begin
  for i:=1 to lim do begin l0[i]:=oo; r0[i]:=-oo; l1[i]:=oo; r1[i]:=-oo; end;
  readln(n,m);
  cnt:=0;
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
  begin
    readln(x,y);
    addedges(x,y);
    addedges(y,x);
  end;
  time:=0;
  dfs(1,1);
  for i:=1 to m do
  begin
    read(kind,x);
    if (kind=2) then
    begin
      readln;
      z:=a[x];
      x:=ps[x];
      writeln(z+sum(depth[x] mod 2,1,1,n,x));
    end
    else
    begin
      readln(y);
      x:=ps[x];
      if (depth[x] mod 2=0) then
      begin
        if (l0[x]<>oo) then modify(0,1,1,n,l0[x],r0[x],y);
        if (l1[x]<>oo) then modify(1,1,1,n,l1[x],r1[x],-y);
      end
      else
      begin
        if (l1[x]<>oo) then modify(1,1,1,n,l1[x],r1[x],y);
        if (l0[x]<>oo) then modify(0,1,1,n,l0[x],r0[x],-y);
      end;
    end;
  end;
end.