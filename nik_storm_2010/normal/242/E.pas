uses math; const size=100000;
var
  t:array[0..19,1..4*size] of int64; a:array[1..size] of int64; ch:array[0..19,1..4*size] of boolean;
  b:array[0..19,1..size] of longint; tip,n,m,i,j,l,r,x:longint; ans:int64;


procedure build(nom,i,l,r:longint);
var m:longint;
begin
  if (l=r) then t[nom,i]:=b[nom,l] else
  begin
    m:=(l+r) div 2;
    build(nom,i*2,l,m); build(nom,i*2+1,m+1,r);
    t[nom,i]:=t[nom,i*2]+t[nom,i*2+1];
  end;
end;


function f(nom,i,l,r:longint):int64;
begin
  if (ch[nom,i]) then exit((r-l+1)-t[nom,i]) else exit(t[nom,i]);
end;


procedure modify(nom,i,l,r,ql,qr:longint);
var m:longint;
begin
  if (l=ql) and (r=qr) then ch[nom,i]:=ch[nom,i] xor true else
  begin
    if (ch[nom,i]) then
    begin
      ch[nom,i*2]:=ch[nom,i*2] xor true;
      ch[nom,i*2+1]:=ch[nom,i*2+1] xor true;
      ch[nom,i]:=false;
      t[nom,i]:=(r-l+1)-t[nom,i];
    end;
    m:=(l+r) div 2;
    if (ql<=m) then modify(nom,i*2,l,m,ql,min(qr,m));
    if (m<qr) then modify(nom,i*2+1,m+1,r,max(ql,m+1),qr);
    t[nom,i]:=f(nom,i*2,l,m)+f(nom,i*2+1,m+1,r);
  end;
end;


function find(nom,i,l,r,ql,qr:longint):int64;
var res,m:longint;
begin
  if (l=ql) and (r=qr) then exit(f(nom,i,l,r)) else
  begin
    if (ch[nom,i]) then
    begin
      ch[nom,i*2]:=ch[nom,i*2] xor true;
      ch[nom,i*2+1]:=ch[nom,i*2+1] xor true;
      ch[nom,i]:=false;
      t[nom,i]:=(r-l+1)-t[nom,i];
    end;
    m:=(l+r) div 2; res:=0;
    if (ql<=m) then res:=res+find(nom,i*2,l,m,ql,min(qr,m));
    if (m<qr) then res:=res+find(nom,i*2+1,m+1,r,max(ql,m+1),qr);
    exit(res);
  end;
end;


begin
  read(n); for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    for j:=0 to 19 do
    if (a[i] and (1 shl j)<>0) then b[j,i]:=1 else b[j,i]:=0;
  end;
  for j:=0 to 19 do build(j,1,1,n);
  readln(m);
  for i:=1 to m do
  begin
    read(tip);
    if (tip=1) then
    begin
      readln(l,r); ans:=0;
      for j:=0 to 19 do ans:=ans+find(j,1,1,n,l,r)*int64(1 shl j);
      writeln(ans);
    end
      else
    begin
      readln(l,r,x);
      for j:=0 to 19 do if (x and (1 shl j)<>0) then modify(j,1,1,n,l,r);
    end;
  end;
end.