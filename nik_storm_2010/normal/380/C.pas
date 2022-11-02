const
  lim=1000010;
var
  st,pos,tree:array[0..lim] of longint;
  l,r,nom,res:array[0..200000] of longint;
  s:ansistring;
  d,i,cnt,n,j:longint;

procedure sort(left,right:longint);
var
  i,j,d,w:longint;
begin
  i:=left; j:=right;
  d:=r[random(right-left+1)+left];
  while (i<=j) do
  begin
    while (r[i]<d) do inc(i);
    while (r[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=l[i]; l[i]:=l[j]; l[j]:=w;
      w:=r[i]; r[i]:=r[j]; r[j]:=w;
      w:=nom[i]; nom[i]:=nom[j]; nom[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<right) then sort(i,right);
  if (left<j) then sort(left,j);
end;

procedure modify(x:longint);
begin
  while (x<=lim) do
  begin
    tree[x]:=tree[x]+2;
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
    res:=res+tree[x];
    x:=(x and (x+1))-1;
  end;
  exit(res);
end;

begin
  readln(s);
  d:=length(s);
  cnt:=0;
  for i:=1 to d do
  if (s[i]='(') then
  begin
    inc(cnt);
    st[cnt]:=i;
  end
  else
  begin
    if (cnt=0) then pos[i]:=-1 else
    begin
      pos[i]:=st[cnt];
      dec(cnt);
    end;
  end;
  readln(n);
  for i:=1 to n do
  begin
    readln(l[i],r[i]);
    nom[i]:=i;
  end;
  randomize;
  sort(1,n);
  j:=1;
  for i:=1 to n do
  begin
    while (j<=r[i]) do
    begin
      if (s[j]=')') and (pos[j]<>-1) then modify(pos[j]);
      inc(j);
    end;
    res[nom[i]]:=sum(r[i])-sum(l[i]-1);
  end;
  for i:=1 to n do writeln(res[i]);
end.