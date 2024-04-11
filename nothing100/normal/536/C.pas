type
  bian=record
         point,next:longint;
       end;
var
  n,num,sum,tot:longint;
  bo,po:array [1..200000] of boolean;
  px,py,qx,qy,pz,qz,g,x,y:array [1..200000] of longint;
  b:array [1..200000] of bian;
procedure qsort(xx,yy:longint);
var
  l,r,mid,midd,q:longint;
begin
  l:=xx; r:=yy; mid:=px[(l+r) shr 1]; midd:=py[(l+r) shr 1];
  repeat
    while (px[l]>mid) or ((px[l]=mid) and (py[l]>midd)) do inc(l);
    while (px[r]<mid) or ((px[r]=mid) and (py[r]<midd)) do dec(r);
    if l<=r then
    begin
      q:=px[l]; px[l]:=px[r]; px[r]:=q;
      q:=py[l]; py[l]:=py[r]; py[r]:=q;
      q:=pz[l]; pz[l]:=pz[r]; pz[r]:=q;
      inc(l); dec(r);
    end;
  until l>r;
  if xx<r then qsort(xx,r);
  if l<yy then qsort(l,yy);
end;
function check(xx,yy:longint):boolean;
var
  a,b,c,d:int64;
begin
  a:=(qx[xx-1]-qx[xx])*(qy[xx]-y[yy]);
  b:=(qy[xx-1]-qy[xx])*(qx[xx]-x[yy]);
  a:=a*qy[xx-1]*x[yy]-b*qx[xx-1]*y[yy];
  if a<0 then exit(true)
  else exit(false);
end;
procedure build(x,y:longint);
begin
  inc(tot); b[tot].point:=y; b[tot].next:=g[x]; g[x]:=tot;
end;
procedure init;
var
  i,j,t:longint;
begin
  read(n);
  for i:=1 to n do read(px[i],py[i]);
  for i:=1 to n do pz[i]:=i;
  qsort(1,n);
  inc(sum); x[1]:=px[1]; y[1]:=py[1]; build(1,pz[1]);
  for i:=2 to n do
  if (px[i]=px[i-1]) and (py[i]=py[i-1]) then build(sum,pz[i])
  else
  begin
    inc(sum); x[sum]:=px[i]; y[sum]:=py[i]; build(sum,pz[i]);
  end;
  inc(num); qx[1]:=x[1]; qy[1]:=y[1]; qz[1]:=1;
  for i:=2 to sum do
  begin
    while (num>1) and (check(num,i)) do dec(num);
    inc(num); qx[num]:=x[i]; qy[num]:=y[i]; qz[num]:=i;
  end;
  j:=1;
  while (j<>num) and (qy[j+1]>qy[j]) do inc(j);
  for i:=1 to j do
  begin
    t:=g[qz[i]];
    while t<>0 do
    begin
      bo[b[t].point]:=true;
      t:=b[t].next;
    end;
  end;
  for i:=1 to n do if bo[i] then write(i,' ');
end;
begin
  init;
end.