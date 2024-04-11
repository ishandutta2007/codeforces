uses
  math;
const
  lim=500000;
type
  edges=record too,nxt:longint; end;
var
  ee:array[1..2*lim] of edges;
  start,prev,num,l,r:array[1..lim] of longint;
  used:array[1..lim] of boolean;
  tr,ad:array[1..4*lim] of longint;
  cnt,cur,n,a,b,i,m,tp,v:longint;

procedure add(x,y:longint);
begin
  inc(cnt);
  ee[cnt].too:=y;
  ee[cnt].nxt:=start[x];
  start[x]:=cnt;
end;

procedure dfs(nom,p:longint);
var
  e:longint;
begin
  used[nom]:=true;
  inc(cur);
  num[nom]:=cur;
  l[num[nom]]:=cur;
  prev[num[nom]]:=p;
  e:=start[nom];
  while (e<>0) do
  begin
    if (used[ee[e].too]=false) then dfs(ee[e].too,num[nom]);
    e:=ee[e].nxt;
  end;
  r[num[nom]]:=cur;
end;

procedure modify(i,l,r,ql,qr,zn:longint);
var
  m:longint;
begin
  if (l=ql) and (r=qr) then
  begin
    tr[i]:=(r-l+1)*zn;
    ad[i]:=zn;
  end
    else
  begin
    m:=(l+r) div 2;
    if (ad[i]<>-1) then
    begin
      tr[i*2]:=(m-l+1)*ad[i];
      tr[i*2+1]:=(r-m)*ad[i];
      ad[i*2]:=ad[i];
      ad[i*2+1]:=ad[i];
      ad[i]:=-1;
    end;
    if (ql<=m) then modify(i*2,l,m,ql,min(m,qr),zn);
    if (m<qr) then modify(i*2+1,m+1,r,max(m+1,ql),qr,zn);
    tr[i]:=tr[i*2]+tr[i*2+1];
  end;
end;

function find(i,l,r,ql,qr:longint):longint;
var
  res,m:longint;
begin
  if (l=ql) and (r=qr) then find:=tr[i] else
  begin
    m:=(l+r) div 2;
    if (ad[i]<>-1) then
    begin
      tr[i*2]:=(m-l+1)*ad[i];
      tr[i*2+1]:=(r-m)*ad[i];
      ad[i*2]:=ad[i];
      ad[i*2+1]:=ad[i];
      ad[i]:=-1;
    end;
    res:=0;
    if (ql<=m) then res:=res+find(i*2,l,m,ql,min(m,qr));
    if (m<qr) then res:=res+find(i*2+1,m+1,r,max(m+1,ql),qr);
    find:=res;
  end;
end;

begin
  for i:=1 to 4*lim do ad[i]:=-1;
  readln(n);
  for i:=1 to n-1 do
  begin
    readln(a,b);
    add(a,b); add(b,a);
  end;
  dfs(1,0);
  readln(m);
  for i:=1 to m do
  begin
    readln(tp,v);
    case tp of
    1:
    begin
      v:=num[v];
      if (v<>1) and (find(1,1,n,l[v],r[v])<>r[v]-l[v]+1) then modify(1,1,n,prev[v],prev[v],0);
      modify(1,1,n,l[v],r[v],1);
    end;
    2:
    begin
      v:=num[v];
      modify(1,1,n,v,v,0);
    end;
    3:
    begin
      v:=num[v];
      if (find(1,1,n,l[v],r[v])<>r[v]-l[v]+1) then writeln(0) else writeln(1);
    end;
    end;
  end;
end.