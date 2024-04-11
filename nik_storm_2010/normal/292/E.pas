uses math;
var
    a,b:array[1..100000] of longint; t:array[1..2,1..1000000] of longint;
      code,tek,t1,t2,x,y,z,n,m,i,j:longint;


procedure update(nom:longint);
begin
  t[1,nom*2]:=t[1,nom]; t[2,nom*2]:=t[2,nom];
  t[1,nom*2+1]:=t[1,nom]; t[2,nom*2+1]:=t[2,nom];
  t[1,nom]:=0; t[2,nom]:=0;
end;


procedure modify(i,l,r,ql,qr,d,w:longint);
var m:longint;
begin
  if (l=ql) and (r=qr) then begin t[1,i]:=d; t[2,i]:=w; end
    else
    begin
      if t[1,i]<>0 then update(i);
      m:=(l+r) div 2;
      if (ql<=m) then modify(i*2,l,m,ql,min(qr,m),d,w);
      if (m<qr) then modify(i*2+1,m+1,r,max(ql,m+1),qr,d,w);
    end;
end;


procedure find(i,l,r,nom:longint; var q1,q2:longint);
var m:longint;
begin
  if (l=r) then begin q1:=t[1,i]; q2:=t[2,i]; end else
    begin
      if t[1,i]<>0 then update(i);
      m:=(l+r) div 2;
      if (nom<=m) then find(i*2,l,m,nom,q1,q2) else find(i*2+1,m+1,r,nom,q1,q2);
    end;
end;


begin

  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to m do
    begin
      read(code);
      if code=1 then begin readln(x,y,z); modify(1,1,n,y,y+z-1,x,y); end else
        begin
          readln(x); find(1,1,n,x,t1,t2);
          if (t1=0) and (t2=0) then writeln(b[x]) else writeln(a[t1+(x-t2)]);
        end;
    end;

end.