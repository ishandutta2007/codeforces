const
  ln=20;
  lim=(1 shl ln)+ln;
var
  a,b,tree,cur:array[0..lim] of longint;
  cnt,rev:array[0..ln] of int64;
  quest,all,time,n,i,l,r,m,q:longint;
  ans,swap:int64;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=b[random(r-l+1)+l];
  repeat
    while (b[i]<d) do inc(i);
    while (b[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=b[i]; b[i]:=b[j]; b[j]:=w;
      inc(i);
      dec(j);
    end;
  until (i>j);
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

procedure modify(x:longint);
begin
  while (x<=lim) do
  begin
    if (cur[x]<>time) then begin cur[x]:=time; tree[x]:=0; end;
    inc(tree[x]);
    x:=(x or (x+1));
  end;
end;

function sum(x:longint):longint;
var
  res:longint;
begin
  res:=0;
  while (x>=0) do
  begin
    if (cur[x]=time) then res:=res+tree[x];
    x:=(x and (x+1))-1;
  end;
  sum:=res;
end;

procedure build(dp,l,r:longint);
var
  i,m:longint;
begin
  if (l=r) then exit;
  m:=(l+r) div 2;
  build(dp+1,l,m);
  build(dp+1,m+1,r);
  inc(time);
  for i:=m+1 to r do modify(a[i]);
  for i:=l to m do cnt[dp]:=cnt[dp]+sum(a[i]-1);
  inc(time);
  for i:=l to m do modify(a[i]);
  for i:=m+1 to r do rev[dp]:=rev[dp]+sum(a[i]-1);
end;

begin
  readln(n);
  time:=0;
  all:=1;
  for i:=1 to n do all:=all*2;
  for i:=1 to all do read(a[i]);
  b:=a;
  randomize;
  sort(1,all);
  for i:=1 to all do
  begin
    l:=1; r:=all+1;
    while (r-l>1) do
    begin
      m:=(l+r) div 2;
      if (b[m]>a[i]) then r:=m else l:=m;
    end;
    a[i]:=l;
  end;
  build(0,1,all);
  readln(quest);
  for i:=1 to quest do
  begin
    read(q);
    q:=n-q;
    for l:=q to n do begin swap:=cnt[l]; cnt[l]:=rev[l]; rev[l]:=swap; end;
    ans:=0;
    for l:=0 to n do ans:=ans+cnt[l];
    writeln(ans);
  end;
end.