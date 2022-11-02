uses
  math;
const
  ln=1000;
  lm=3000;
type
  edges=record
    t,l,r,n:longint;
  end;
var
  ee:array[1..2*lm] of edges;
  rr,start:array[1..lm] of longint;
  used:array[1..ln] of boolean;
  ans,cnt,n,m,i,j,a,b,c,d:longint;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=rr[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (rr[i]<d) do inc(i);
    while (rr[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=rr[i]; rr[i]:=rr[j]; rr[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

procedure add(a,b,c,d:longint);
begin
  inc(cnt);
  ee[cnt].t:=b;
  ee[cnt].l:=c;
  ee[cnt].r:=d;
  ee[cnt].n:=start[a];
  start[a]:=cnt;
end;

procedure dfs(nom,l,r:longint);
var
  e:longint;
begin
  used[nom]:=true;
  e:=start[nom];
  while (e<>0) do
  begin
    if (not used[ee[e].t]) and (ee[e].l<=l) and (r<=ee[e].r) then dfs(ee[e].t,l,r);
    e:=ee[e].n;
  end;
end;

begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(a,b,c,d);
    add(a,b,c,d);
    add(b,a,c,d);
    rr[i]:=d;
  end;
  randomize;
  sort(1,m);
  ans:=-1;
  for i:=1 to m do
  begin
    for j:=1 to m do if (rr[j]>ee[i*2-1].l) then begin a:=j; break; end;
    b:=m+1;
    while (b-a>1) do
    begin
      c:=(a+b) div 2;
      fillchar(used,sizeof(used),false);
      dfs(1,ee[i*2-1].l,rr[c]);
      if (used[n]) then a:=c else b:=c;
    end;
    fillchar(used,sizeof(used),false);
    dfs(1,ee[i*2-1].l,rr[a]);
    if (used[n]) then ans:=max(ans,rr[a]-ee[i*2-1].l+1);
  end;
  if (ans=-1) then writeln('Nice work, Dima!') else writeln(ans);
end.