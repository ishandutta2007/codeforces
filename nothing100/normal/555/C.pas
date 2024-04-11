type
  tree=record
         s:array [0..1] of longint;
         f:longint;
       end;
var
  n,m:longint;
  num:array [0..1] of longint;
  tr:array [0..1,1..1000000] of tree;
  bo:array [1..200000] of boolean;
  tmp:array [1..2,0..200000,1..2] of longint;
  a,b:array [1..200000] of longint;
  ch:array [1..200000] of char;
procedure new(z:longint; var x:longint);
begin
  if x=0 then
  begin
    inc(num[z]);
    x:=num[z];
  end;
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
function get(z,wh,l,r,x:longint):longint;
var
  mid,tmp:longint;
begin
  tmp:=tr[z,wh].f;
  if l=r then exit(tmp);
  mid:=(l+r) shr 1;
  if x<=mid then
  begin
    if tr[z,wh].s[0]<>0 then tmp:=max(tmp,get(z,tr[z,wh].s[0],l,mid,x));
  end
  else
  begin
    if tr[z,wh].s[1]<>0 then tmp:=max(tmp,get(z,tr[z,wh].s[1],mid+1,r,x));
  end;
  exit(tmp);
end;
procedure ins(z,wh,l,r,x,y,h:longint);
var
  mid:longint;
begin
  if (r<x) or (l>y) then exit;
  if (l>=x) and (r<=y) then
  begin
    tr[z,wh].f:=max(tr[z,wh].f,h);
    exit;
  end;
  mid:=(l+r) shr 1;
  new(z,tr[z,wh].s[0]);
  new(z,tr[z,wh].s[1]);
  ins(z,tr[z,wh].s[0],l,mid,x,y,h);
  ins(z,tr[z,wh].s[1],mid+1,r,x,y,h);
end;
procedure qsort(z,x,y:longint);
var
  l,r,mid,q:longint;
begin
  l:=x; r:=y;
  mid:=tmp[z,(x+y) shr 1,1];
  repeat
    while tmp[z,l,1]<mid do inc(l);
    while tmp[z,r,1]>mid do dec(r);
    if l<=r then
    begin
      q:=tmp[z,l,1]; tmp[z,l,1]:=tmp[z,r,1]; tmp[z,r,1]:=q;
      q:=tmp[z,l,2]; tmp[z,l,2]:=tmp[z,r,2]; tmp[z,r,2]:=q;
      inc(l); dec(r);
    end;
  until l>r;
  if x<r then qsort(z,x,r);
  if l<y then qsort(z,l,y);
end;
procedure init;
var
  i,o,p,t:longint;
begin
  readln(n,m);
  num[1]:=1;
  num[0]:=1;
  for i:=1 to m do
  begin
    read(a[i],b[i]);
    read(ch[i]);
    while (ch[i]<>'L') and (ch[i]<>'U') do read(ch[i]);
    readln;
  end;
  for i:=1 to m do
  begin
    tmp[1,i,1]:=a[i];
    tmp[1,i,2]:=i;
  end;
  qsort(1,1,m);
  o:=1;
  a[tmp[1,1,2]]:=1;
  for i:=2 to m do
  begin
  if tmp[1,i,1]<>tmp[1,i-1,1] then o:=i;
  a[tmp[1,i,2]]:=o;
  end;
  for i:=1 to m do
  begin
    tmp[2,i,1]:=b[i];
    tmp[2,i,2]:=i;
  end;
  qsort(2,1,m);
  o:=1;
  b[tmp[2,1,2]]:=1;
  for i:=1 to m do
  begin
  if tmp[2,i,1]<>tmp[2,i-1,1] then o:=i;
  b[tmp[2,i,2]]:=o;
  end;
  for i:=1 to m do
  begin
    if bo[a[i]] then writeln(0)
    else
    begin
    if ch[i]='U' then
    begin
      t:=get(0,1,0,m,a[i]);
      writeln(tmp[2,b[i],1]-tmp[2,t,1]);
      ins(1,1,0,m,t,b[i],a[i]);
    end
    else
    begin
      t:=get(1,1,0,m,b[i]);
      writeln(tmp[1,a[i],1]-tmp[1,t,1]);
      ins(0,1,0,m,t,a[i],b[i]);
    end;
    end;
    bo[a[i]]:=true;
  end;
end;
begin
  init;
end.