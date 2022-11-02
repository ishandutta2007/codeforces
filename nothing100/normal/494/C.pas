type
  ques=record
         l,r:longint;
         p:double;
       end;
var
  ans:double;
  n,m:longint;
  ma:array [1..100000,0..20] of longint;
  qu:array [1..5010] of ques;
  use:array [1..5010] of boolean;
  tmp:array [0..5010] of double;
  big:array [1..5010] of longint;
  f:array [1..5010,0..5010] of double;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure qsort(x,y:longint);
var
  l,r,mid:longint;
  tmp:ques;
begin
  l:=x; r:=y; mid:=qu[(l+r) shr 1].r-qu[(l+r) shr 1].l;
  repeat
    while (qu[l].r-qu[l].l)<mid do inc(l);
    while (qu[r].r-qu[r].l)>mid do dec(r);
    if l<=r then
    begin
      tmp:=qu[l]; qu[l]:=qu[r]; qu[r]:=tmp;
      inc(l); dec(r);
    end;
  until l>r;
  if x<r then qsort(x,r);
  if l<y then qsort(l,y);
end;
procedure init;
var
  i,j,k,o:longint;
begin
  read(n,m);
  for i:=1 to n do read(ma[i,0]);
  for i:=1 to 17 do
  for j:=1 to n do
  begin
    if j+1 shl (i-1)>n then ma[j,i]:=ma[j,i-1]
    else ma[j,i]:=max(ma[j,i-1],ma[j+1 shl (i-1),i-1]);
  end;
  for i:=1 to m do read(qu[i].l,qu[i].r,qu[i].p);
  inc(m); qu[m].l:=1; qu[m].r:=n; qu[m].p:=0;
  qsort(1,m);
  for i:=1 to m do
  begin
    j:=trunc(ln(qu[i].r-qu[i].l+1)/ln(2));
    big[i]:=max(ma[qu[i].l,j],ma[qu[i].r-1 shl j+1,j]);
  end;
  for i:=1 to m do
  begin
    for j:=0 to m do tmp[j]:=1;
    for j:=1 to (i-1) do
    if (qu[i].l<=qu[j].l) and (qu[i].r>=qu[j].r) and (not use[j]) then
    begin
      use[j]:=true;
      for k:=0 to m do
      begin
        if big[i]+k-big[j]>m then break;
        tmp[k]:=tmp[k]*f[j,big[i]+k-big[j]];
      end;
    end;
    for j:=m downto 1 do tmp[j]:=tmp[j]-tmp[j-1];
    f[i,0]:=tmp[0]*(1-qu[i].p);
    for j:=1 to m do f[i,j]:=f[i,j-1]+tmp[j]*(1-qu[i].p)+tmp[j-1]*qu[i].p;
  end;
  ans:=ans+f[m,0]*big[m];
  for i:=1 to m do ans:=ans+(f[m,i]-f[m,i-1])*(big[m]+i);
  writeln(ans:0:9);
end;
begin
  init;
end.