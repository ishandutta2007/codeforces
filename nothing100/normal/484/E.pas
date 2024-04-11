type
  tree=record
         ls,rs,sum,lsum,rsum:longint;
       end;
var
  n,m,tot,num:longint;
  a,h,w:array [0..100000] of longint;
  ans:array [1..100000] of longint;
  qu,tmp,tmpp:array [1..100000,1..4] of longint;
  tr:array [0..300000] of tree;
procedure qsort(x,y:longint);
var
  l,r,mid,q:longint;
begin
  l:=x; r:=y; mid:=a[(l+r) shr 1];
  repeat
    while (a[l]>mid) do inc(l);
    while (a[r]<mid) do dec(r);
    if l<=r then
    begin
      q:=a[l]; a[l]:=a[r]; a[r]:=q;
      q:=h[l]; h[l]:=h[r]; h[r]:=q;
      inc(l); dec(r);
    end;
  until l>r;
  if x<r then qsort(x,r);
  if l<y then qsort(l,y);
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure maintain(x:longint);
begin
  tr[x].sum:=max(tr[tr[x].ls].sum,tr[tr[x].rs].sum);
  tr[x].sum:=max(tr[x].sum,tr[tr[x].ls].rsum+tr[tr[x].rs].lsum);
  tr[x].lsum:=tr[tr[x].ls].lsum;
  tr[x].rsum:=tr[tr[x].rs].rsum;
end;
procedure ins(wh,x,y,z:longint);
var
  mid:longint;
begin
  if x=y then
  begin
    tr[wh].sum:=tr[wh].sum xor 1;
    tr[wh].lsum:=tr[wh].sum;
    tr[wh].rsum:=tr[wh].sum;
    exit;
  end;
  mid:=(x+y) shr 1;
  if z<=mid then
  begin
    if tr[wh].ls=0 then
    begin
      inc(num);
      tr[wh].ls:=num;
    end;
    ins(tr[wh].ls,x,mid,z);
  end
  else
  begin
    if tr[wh].rs=0 then
    begin
      inc(num);
      tr[wh].rs:=num;
    end;
    ins(tr[wh].rs,mid+1,y,z);
  end;
  maintain(wh);
  if tr[wh].lsum=mid-x+1 then tr[wh].lsum:=tr[wh].lsum+tr[tr[wh].rs].lsum;
  if tr[wh].rsum=y-mid then tr[wh].rsum:=tr[wh].rsum+tr[tr[wh].ls].rsum;
end;
function get(wh,l,r,x,y:longint):tree;
var
  mid:longint;
  o,p,t:tree;
begin
  if (l>=x) and (r<=y) then exit(tr[wh]);
  mid:=(l+r) shr 1;
  if y<=mid then exit(get(tr[wh].ls,l,mid,x,y))
  else if x>mid then exit(get(tr[wh].rs,mid+1,r,x,y))
  else
  begin
    o:=get(tr[wh].ls,l,mid,x,mid);
    p:=get(tr[wh].rs,mid+1,r,mid+1,y);
    t.sum:=max(o.sum,p.sum);
    t.sum:=max(t.sum,o.rsum+p.lsum);
    t.rsum:=p.rsum;
    t.lsum:=o.lsum;
    if t.lsum=mid-x+1 then t.lsum:=t.lsum+p.lsum;
    if t.rsum=y-mid then t.rsum:=t.rsum+o.rsum;
  end;
  exit(t);
end;
procedure solve(l,r,x,y:longint);
var
  i,mid,o,p:longint;
begin
  if l=r then
  begin
    for i:=x to y do ans[qu[i,4]]:=a[w[l]];
    exit;
  end;
  mid:=(l+r) shr 1; o:=0; p:=0;
  for i:=w[l-1]+1 to w[mid] do ins(1,1,n,h[i]);
  for i:=x to y do
  if get(1,1,n,qu[i,1],qu[i,2]).sum<qu[i,3] then
  begin
    inc(o);
    tmp[o]:=qu[i];
  end
  else
  begin
    inc(p);
    tmpp[p]:=qu[i];
  end;
  for i:=1 to o do qu[x+i-1]:=tmp[i];
  for i:=1 to p do qu[x+o+i-1]:=tmpp[i];
  solve(mid+1,r,x,x+o-1);
  for i:=w[l-1]+1 to w[mid] do ins(1,1,n,h[i]);
  solve(l,mid,x+o,y);
end;
procedure init;
var
  i:longint;
begin
  read(n); num:=1;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do h[i]:=i;
  qsort(1,n);
  for i:=2 to n do if a[i]<>a[i-1] then
  begin
    inc(tot); w[tot]:=i-1;
  end;
  inc(tot); w[tot]:=n;
  read(m);
  for i:=1 to m do
  begin
    read(qu[i,1],qu[i,2],qu[i,3]);
    qu[i,4]:=i;
  end;
  solve(1,tot,1,m);
  for i:=1 to m do writeln(ans[i]);
end;
begin
  init;
end.