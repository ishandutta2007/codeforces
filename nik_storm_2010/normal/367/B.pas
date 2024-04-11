const
  l=200000;
var
  a,b,c,all,per,need:array[1..2*l] of int64;
  used:array[1..2*l] of boolean;
  n,m,p,cnt,size,ok,have:int64;
  i:longint;

procedure sort(l,r:int64);
var
  i,j,d,w:int64;
begin
  i:=l; j:=r;
  d:=c[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (c[i]<d) do inc(i);
    while (c[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=c[i]; c[i]:=c[j]; c[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

function dix(x:int64):int64;
var
  l,r,m:int64;
begin
  l:=1; r:=cnt+1;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (x<c[m]) then r:=m else l:=m;
  end;
  exit(l);
end;

procedure modify(nom,x:int64);
begin
  if (per[x]<>nom) then begin per[x]:=nom; all[x]:=0; end;
  if (need[x]<>0) and (all[x]=need[x]) then dec(ok);
  inc(all[x]);
  if (need[x]<>0) and (all[x]=need[x]) then inc(ok);
end;

procedure check(nom:int64);
var
  i:longint;
  x,y:int64;
begin
  ok:=0;
  for i:=1 to m do
  begin
    x:=nom+(i-1)*p;
    modify(nom,a[x]);
  end;
  if (ok=have) then used[nom]:=true;
  x:=nom;
  while (x+m*p)<=n do
  begin
    if (need[a[x]]<>0) and (all[a[x]]=need[a[x]]) then dec(ok);
    dec(all[a[x]]);
    if (need[a[x]]<>0) and (all[a[x]]=need[a[x]]) then inc(ok);
    x:=x+p;
    modify(nom,a[x+(m-1)*p]);
    if (ok=have) then used[x]:=true;
  end;
end;

begin
  readln(n,m,p);
  for i:=1 to n do
  begin
    read(a[i]);
    c[i]:=a[i];
  end;
  for i:=1 to m do
  begin
    read(b[i]);
    c[n+i]:=b[i];
  end;
  randomize;
  sort(1,n+m);
  cnt:=1;
  for i:=2 to n+m do if (c[i]<>c[cnt]) then begin inc(cnt); c[cnt]:=c[i]; end;
  for i:=1 to n do a[i]:=dix(a[i]);
  for i:=1 to m do b[i]:=dix(b[i]);
  for i:=1 to m do
  begin
    if (need[b[i]]=0) then inc(have);
    inc(need[b[i]]);
  end;
  for i:=1 to p do if (i+(m-1)*p<=n) then check(i);
  size:=0;
  for i:=1 to n do if (used[i]) then inc(size);
  writeln(size);
  for i:=1 to n do if (used[i]) then write(i,' ');
end.