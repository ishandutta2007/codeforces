const
  max=10000000000010;
  ll=100010;
type
  edges=record
    t,n:longint;
  end;
var
  a,s,used,was:array[1..ll] of longint;
  ee:array[1..2*ll] of edges;
  take:array[1..ll] of boolean;
  cnt,n,i:longint;
  sum,c,x,y,l,r,m,now,j:int64;

procedure dfs(x:longint);
var
  c:array[1..32] of longint;
  size,e,sum,i:longint;
begin
  take[x]:=true;
  sum:=0;
  e:=s[x];
  while (e<>0) do
  begin
    if (not take[ee[e].t]) then inc(sum);
    e:=ee[e].n;
  end;
  size:=0;
  i:=2;
  while (i*i<=sum) do
  begin
    while (sum mod i=0) do begin inc(size); c[size]:=i; sum:=sum div i; end;
    inc(i);
  end;
  if (sum>1) then begin inc(size); c[size]:=sum; end;
  for i:=1 to size do if (used[c[i]]<>0) then dec(used[c[i]]);
  e:=s[x];
  while (e<>0) do
  begin
    if (not take[ee[e].t]) then dfs(ee[e].t);
    e:=ee[e].n;
  end;
  for i:=1 to size do inc(used[c[i]]);
end;

function maybe(x:longint;sum:int64):boolean;
var
  cnt,e:longint;
  zn:boolean;
begin
  if (x=1) then fillchar(take,sizeof(take),false);
  take[x]:=true;
  e:=s[x];
  cnt:=0;
  while (e<>0) do
  begin
    if (not take[ee[e].t]) then inc(cnt);
    e:=ee[e].n;
  end;
  if (cnt=0) then
  begin
    if (sum<=a[x]) then exit(true) else exit(false);
  end
    else
  begin
    e:=s[x];
    while (e<>0) do
    begin
      if (not take[ee[e].t]) then
      begin
        zn:=maybe(ee[e].t,sum div cnt);
        if (zn=false) then exit(false);
      end;
      e:=ee[e].n;
    end;
    maybe:=true;
  end;
end;

begin
  readln(n);
  for i:=1 to n do begin read(a[i]); sum:=sum+a[i]; end;
  for i:=1 to n-1 do
  begin
    readln(x,y);
    inc(cnt);
    ee[cnt].t:=y; ee[cnt].n:=s[x]; s[x]:=cnt;
    inc(cnt);
    ee[cnt].t:=x; ee[cnt].n:=s[y]; s[y]:=cnt;
  end;
  dfs(1);
  c:=1;
  x:=1;
  j:=2;
  while (j<=ll) do
  begin
    while (used[j]<>0) do
    begin
      dec(used[j]);
      c:=c*j;
      if (c>max) then break;
    end;
    inc(j);
  end;
  l:=0; r:=max div c+1;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (maybe(1,m*c)) then l:=m else r:=m;
  end;
  if (maybe(1,r*c)) then writeln(sum-r*c) else writeln(sum-l*c);
end.