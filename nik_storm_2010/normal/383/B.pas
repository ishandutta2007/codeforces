const
  lim=300000;
var
  x,y:array[0..lim] of longint;
  l,r:array[0..1,0..lim] of longint;
  time,now,cnt,i,j,n,m,k,left,new:longint;

procedure sort(l,r:longint);
var
  i,j,dx,dy,w:longint;
begin
  i:=l; j:=r;
  w:=random(r-l+1)+l;
  dx:=x[w];
  dy:=y[w];
  while (i<=j) do
  begin
    while (x[i]<dx) or ((x[i]=dx) and (y[i]<dy)) do inc(i);
    while (x[j]>dx) or ((x[j]=dx) and (y[j]>dy)) do dec(j);
    if (i<=j) then
    begin
      w:=x[i]; x[i]:=x[j]; x[j]:=w;
      w:=y[i]; y[i]:=y[j]; y[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

procedure bad;
begin
  writeln(-1);
  halt;
end;

procedure add(x,y:longint);
begin
  if (x>y) then exit;
  if (r[now,new]>=x) then exit;
  inc(new);
  l[now,new]:=x;
  r[now,new]:=y;
end;

begin
  readln(n,m);
  for i:=1 to m do readln(x[i],y[i]);
  randomize;
  sort(1,m);
  inc(m);
  x[m]:=n;
  y[m]:=n+1;
  cnt:=1;
  time:=0;
  l[0,1]:=1; r[0,1]:=1;
  i:=1;
  while (i<=m) do
  begin
    if (cnt=0) then bad;
    j:=i;
    while (j<=m) and (x[i]=x[j]) do inc(j);
    if (x[i]<>x[i-1]+1) then
    begin
      cnt:=1;
      l[time,cnt]:=l[time,1];
      r[time,cnt]:=n;
    end;
    now:=1-time;
    new:=0;
    for k:=1 to cnt do
    begin
      if (i=j) then break;
      left:=l[time,k];
      if (r[time,k]<=r[now,new]) then continue;
      while (i<j) and (left>y[i]) do inc(i);
      if (i=j) then begin add(left,n); break; end;
      while (i<j) do
      begin
        add(left,y[i]-1);
        left:=y[i]+1;
        if (left>r[time,k]) then break;
        inc(i);
        if (i=j) then begin add(left,n); break; end;
      end;
    end;
    i:=j;
    cnt:=new;
    time:=1-time;
  end;
  if (r[time,cnt]=n) then writeln((n-1)*2) else bad;
end.