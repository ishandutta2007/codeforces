uses math; const nn=100000;
var
  a:array[1..2,1..nn] of longint; t1,t2:array[1..4*nn] of longint;
  x:array[1..nn] of longint; ans,cnt,n,k,i,l,r:longint;


procedure build1(i,l,r:longint);
var m:longint;
begin
  if (l=r) then t1[i]:=x[l] else
  begin
    m:=(l+r) div 2;
    build1(i*2,l,m); build1(i*2+1,m+1,r);
    t1[i]:=min(t1[i*2],t1[i*2+1]);
  end;
end;


function find1(i,l,r,ql,qr:longint):longint;
var res,m:longint;
begin
  if (ql=l) and (qr=r) then exit(t1[i]);
  res:=maxlongint; m:=(l+r) div 2;
  if (ql<=m) then res:=min(res,find1(i*2,l,m,ql,min(qr,m)));
  if (m<qr) then res:=min(res,find1(i*2+1,m+1,r,max(ql,m+1),qr));
  find1:=res;
end;


procedure build2(i,l,r:longint);
var m:longint;
begin
  if (l=r) then t2[i]:=x[l] else
  begin
    m:=(l+r) div 2;
    build2(i*2,l,m); build2(i*2+1,m+1,r);
    t2[i]:=max(t2[i*2],t2[i*2+1]);
  end;
end;


function find2(i,l,r,ql,qr:longint):longint;
var res,m:longint;
begin
  if (ql=l) and (qr=r) then exit(t2[i]);
  res:=0; m:=(l+r) div 2;
  if (ql<=m) then res:=max(res,find2(i*2,l,m,ql,min(qr,m)));
  if (m<qr) then res:=max(res,find2(i*2+1,m+1,r,max(ql,m+1),qr));
  find2:=res;
end;


begin
  readln(n,k); for i:=1 to n do read(x[i]);
  build1(1,1,n); build2(1,1,n);
  l:=1;
  for r:=1 to n do
  begin
    while (abs(find1(1,1,n,l,r)-x[r])>k) or (abs(find2(1,1,n,l,r)-x[r])>k)
    do inc(l);
    if (r-l+1>=ans) then
    begin
      if (r-l+1>ans) then begin ans:=r-l+1; cnt:=0; end;
      inc(cnt); a[1,cnt]:=l; a[2,cnt]:=r;
    end;
  end;
  writeln(ans,' ',cnt);
  for i:=1 to cnt do writeln(a[1,i],' ',a[2,i]);
end.