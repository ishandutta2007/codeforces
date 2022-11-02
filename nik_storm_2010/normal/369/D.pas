uses
  math;
const
  ll=3000+10;
var
  q:array[1..2,1..ll*ll] of longint;
  l:array[1..ll,1..ll] of longint;
  p,kind:array[1..ll] of longint;
  ans,st,fn,i,n,k,x,y,ma,j:longint;
  one:boolean;

procedure into(x,y,z:longint);
begin
  if (l[x,y]=maxlongint) then
  begin
    q[1,fn]:=x;
    q[2,fn]:=y;
    inc(fn);
  end;
  l[x,y]:=min(l[x,y],z)
end;

procedure from(var x,y:longint);
begin
  x:=q[1,st];
  y:=q[2,st];
  inc(st);
end;

begin
  readln(n,k);
  for i:=1 to n do read(p[i]);
  for i:=1 to n do
  begin
    ma:=-maxlongint;
    one:=false;
    for j:=i to n do
    begin
      ma:=max(ma,p[j]);
      if (p[j]=100) then one:=true;
    end;
    if (one) then begin kind[i]:=100; continue; end;
    if (ma=0) then begin kind[i]:=0; continue; end;
    kind[i]:=50;
  end;
  for i:=1 to ll do for j:=1 to ll do l[i,j]:=maxlongint;
  st:=1; fn:=1;
  into(1,2,0);
  while (st<>fn) do
  begin
    from(x,y);
    if (l[x,y]>k) then continue;
    inc(ans);
    if (x>n) then continue;
    if (y<=n) and (p[x]<>0) and (kind[y]<>100) then into(x,y+1,l[x,y]+1);
    if (y<=n) and (kind[y]<>0) and (p[x]<>100) then into(y,y+1,l[x,y]+1);
    if (y<=n) and (p[x]<>0) and (kind[y]<>0) then into(y+1,y+2,l[x,y]+1);
  end;
  writeln(ans);
end.