uses
  math;
const
  lim=400000;
type
  point=record
    x,y,z:int64;
  end;
var
  a,b:array[1..lim] of point;
  heap,res:array[0..lim] of int64;
  n,m,s,l,r,mid,size:int64;
  i:longint;

procedure sorta(l,r:int64);
var
  i,j,d,w:int64;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l].x;
  while (i<=j) do
  begin
    while (a[i].x<d) do inc(i);
    while (a[j].x>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i].x; a[i].x:=a[j].x; a[j].x:=w;
      w:=a[i].z; a[i].z:=a[j].z; a[j].z:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sorta(i,r);
  if (l<j) then sorta(l,j);
end;

procedure sortb(l,r:int64);
var
  i,j,d,w:int64;
begin
  i:=l; j:=r;
  d:=b[random(r-l+1)+l].x;
  while (i<=j) do
  begin
    while (b[i].x<d) do inc(i);
    while (b[j].x>d) do dec(j);
    if (i<=j) then
    begin
      w:=b[i].x; b[i].x:=b[j].x; b[j].x:=w;
      w:=b[i].y; b[i].y:=b[j].y; b[j].y:=w;
      w:=b[i].z; b[i].z:=b[j].z; b[j].z:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sortb(i,r);
  if (l<j) then sortb(l,j);
end;

procedure addh(x:int64);
var
  i,w:int64;
begin
  inc(size);
  heap[size]:=x;
  i:=size;
  while (i>1) and (b[heap[i div 2]].y>b[heap[i]].y) do
  begin
    w:=heap[i div 2];
    heap[i div 2]:=heap[i];
    heap[i]:=w;
    i:=i div 2;
  end;
end;

procedure delh;
var
  i,w,nom:int64;
begin
  heap[1]:=heap[size];
  dec(size);
  i:=1;
  while (i*2<=size) do
  begin
    nom:=i*2;
    if (i*2+1<=size) and (b[heap[i*2+1]].y<b[heap[nom]].y) then nom:=i*2+1;
    if (b[heap[i]].y>b[heap[nom]].y) then
    begin
      w:=heap[i];
      heap[i]:=heap[nom];
      heap[nom]:=w;
      i:=nom;
    end
    else break;
  end;
end;

function check(x:int64):boolean;
var
  i,j,sum:int64;
begin
  size:=0; sum:=0;
  j:=m;
  i:=n;
  while (i>=1) do
  begin
    if (b[i].x>=a[j].x) then
    begin
      addh(i);
      dec(i);
    end
    else
    begin
      if (size=0) then exit(false);
      sum:=sum+b[heap[1]].y;
      delh;
      j:=j-x;
      if (j<1) then break;
    end;
  end;
  while (j>=1) do
  begin
    if (size=0) then exit(false);
    sum:=sum+b[heap[1]].y;
    delh;
    j:=j-x;
  end;
  if (sum<=s) then exit(true) else exit(false);
end;

procedure answer(x:int64);
var
  i,j:int64;
  k:longint;
begin
  size:=0;
  j:=m;
  i:=n;
  while (i>=1) do
  begin
    if (b[i].x>=a[j].x) then
    begin
      addh(i);
      dec(i);
    end
    else
    begin
      for k:=j downto max(1,j-x+1) do res[a[k].z]:=b[heap[1]].z;
      delh;
      j:=j-x;
      if (j<1) then break;
    end;
  end;
  while (j>=1) do
  begin
    for k:=j downto max(1,j-x+1) do res[a[k].z]:=b[heap[1]].z;
    delh;
    j:=j-x;
  end;
  writeln('YES');
  for k:=1 to m do write(res[k],' ');
  halt;
end;

begin
  readln(n,m,s);
  for i:=1 to m do begin read(a[i].x); a[i].z:=i; end;
  readln;
  for i:=1 to n do begin read(b[i].x); b[i].z:=i; end;
  readln;
  for i:=1 to n do read(b[i].y);
  randomize;
  sorta(1,m);
  sortb(1,n);
  l:=1; r:=m;
  while (r-l>1) do
  begin
    mid:=(l+r) div 2;
    if (check(mid)) then r:=mid else l:=mid;
  end;
  if (check(l)) then answer(l);
  if (check(r)) then answer(r);
  writeln('NO');
end.