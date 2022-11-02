const size=200000;
var
  map:array[0..size] of array of longint; used:array[0..size] of array of boolean; c,l:array[0..size] of longint;
  a,q:array[1..3,0..size] of longint; cnt,ras,st,fn,x0,y0,x1,y1,n,k,i,j,r,x,y:longint;


procedure quicksort(l,r:longint);
var i,j,d1,d2,w:longint;
begin
  i:=l; j:=r; w:=random(r-l+1)+l; d1:=a[1,w]; d2:=a[2,w];
  while i<=j do
  begin
    while (a[1,i]<d1) or ((a[1,i]=d1) and (a[2,i]<d2)) do inc(i);
    while (a[1,j]>d1) or ((a[1,j]=d1) and (a[2,j]>d2)) do dec(j);
    if i<=j then
    begin
      w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
      w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
      inc(i); dec(j);
    end;
  end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


procedure add(x,y,z:longint);
begin
  used[x,y]:=true;
  q[1,fn]:=x; q[2,fn]:=y; q[3,fn]:=z;
  inc(fn);
end;


procedure out(var x,y,z:longint);
begin
  x:=q[1,st]; y:=q[2,st]; z:=q[3,st];
  inc(st);
end;


function find(nom,c:longint):longint;
var le,ri,m:longint;
begin
  le:=1; ri:=l[nom];
  while (ri-le>1) do
  begin
    m:=(le+ri) div 2;
    if map[nom,m]<c then le:=m else ri:=m;
  end;
  if map[nom,le]=c then find:=le else
  if map[nom,ri]=c then find:=ri else find:=-1;
end;


begin

  readln(x0,y0,x1,y1); readln(n); k:=0;
  for i:=1 to n do
  begin
    readln(r,x,y);
    for j:=x to y do begin inc(k); a[1,k]:=r; a[2,k]:=j; end;
  end;
  randomize; quicksort(1,k); cnt:=0;
  for i:=1 to k do
    if not((a[1,i]=a[1,i-1]) and (a[2,i]=a[2,i-1])) then
    begin
      if (cnt=0) or (c[cnt]<>a[1,i]) then inc(cnt);
      inc(l[cnt]); c[cnt]:=a[1,i];
      setlength(map[cnt],l[cnt]+1); setlength(used[cnt],l[cnt]+1);
      map[cnt,l[cnt]]:=a[2,i];
    end;
  for i:=1 to cnt do if c[i]=x0 then
  begin
    x0:=i;
    for j:=1 to l[i] do if map[i,j]=y0 then y0:=j;
  end;
  st:=1; fn:=1; add(x0,y0,0);
  while st<>fn do
  begin
    out(x0,y0,ras); if (c[x0]=x1) and (map[x0,y0]=y1) then begin writeln(ras); halt; end;
    if (y0<>1) and (map[x0,y0-1]=map[x0,y0]-1) and (not used[x0,y0-1]) then add(x0,y0-1,ras+1);
    if (y0<>l[x0]) and (map[x0,y0+1]=map[x0,y0]+1) and (not used[x0,y0+1]) then add(x0,y0+1,ras+1);
    if (x0<>1) and (c[x0-1]=c[x0]-1) then
    begin
      x:=find(x0-1,map[x0,y0]-1); if (x<>-1) and (not used[x0-1,x]) then add(x0-1,x,ras+1);
      x:=find(x0-1,map[x0,y0]+0); if (x<>-1) and (not used[x0-1,x]) then add(x0-1,x,ras+1);
      x:=find(x0-1,map[x0,y0]+1); if (x<>-1) and (not used[x0-1,x]) then add(x0-1,x,ras+1);
    end;
    if (x0<>cnt) and (c[x0+1]=c[x0]+1) then
    begin
      x:=find(x0+1,map[x0,y0]-1); if (x<>-1) and (not used[x0+1,x]) then add(x0+1,x,ras+1);
      x:=find(x0+1,map[x0,y0]+0); if (x<>-1) and (not used[x0+1,x]) then add(x0+1,x,ras+1);
      x:=find(x0+1,map[x0,y0]+1); if (x<>-1) and (not used[x0+1,x]) then add(x0+1,x,ras+1);
    end;
  end;
  writeln(-1);

end.