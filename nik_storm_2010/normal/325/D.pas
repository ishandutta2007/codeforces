const d:array[1..2,1..8] of longint=((-1,-1,-1,0,1,1,1,0),(-1,0,1,1,1,0,-1,-1));
var
  a,o:array[1..6000,1..6000] of longint; p,q:array[1..20000000] of longint;
  ans,it,r,c,s,f,x,y,n,i,j,z:longint; ii,jj:longint;


function findset(i:longint):longint;
begin
  if p[i]<>i then p[i]:=findset(p[i]);
  exit(p[i]);
end;


procedure union(a,b:longint);
begin
  a:=findset(a); b:=findset(b);
  if random(2)=1 then p[a]:=b else p[b]:=a;
end;


procedure change(a,b:longint;var x,y:longint);
begin
  if not((1<=a) and (a<=r)) then x:=-1 else x:=a;
  if (b=0) then y:=2*c else if (b=2*c+1) then y:=1 else y:=b;
end;


function maybe(s,f:longint):boolean;
var i,x,y:longint;
begin
  inc(it); maybe:=true;
  for i:=1 to 8 do
  begin
    change(s+d[1,i],f+d[2,i],x,y);
    if (x<>-1) and (y<>-1) and (o[x,y]=1) then q[findset(a[x,y])]:=it;
  end;
  f:=f+c;
  for i:=1 to 8 do
  begin
    change(s+d[1,i],f+d[2,i],x,y);
    if (x<>-1) and (y<>-1) and (o[x,y]=1) and (q[findset(a[x,y])]=it) then exit(false);
  end;
end;


begin

  readln(r,c,n);
  if c=1 then
  begin
    for i:=1 to n do readln(s,f);
    writeln(0); exit;
  end;
  for i:=1 to r do for j:=1 to c do begin inc(z); a[i,j]:=z; p[z]:=z; end;
  for i:=1 to r do for j:=1 to c do begin inc(z); a[i,j+c]:=z; p[z]:=z; end;
  for i:=1 to n do
  begin
    readln(s,f);
    if maybe(s,f) then
    begin
      o[s,f]:=1; o[s,f+c]:=1; inc(ans);
      for j:=1 to 8 do
      begin
        change(s+d[1,j],f+d[2,j],x,y);
        if (x<>-1) and (y<>-1) and (o[x,y]=1) then union(a[s,f],a[x,y]);
      end;
      f:=f+c;
      for j:=1 to 8 do
      begin
        change(s+d[1,j],f+d[2,j],x,y);
        if (x<>-1) and (y<>-1) and (o[x,y]=1) then union(a[s,f],a[x,y]);
      end;
    end;
    {
    for ii:=1 to r do
    begin
      for jj:=1 to c do write(findset(a[ii,jj]):2,' ');
      write('| ');
      for jj:=1 to c do write(findset(a[ii,jj+c]):2,' ');
      writeln;
    end;
    }
  end;
  writeln(ans);

end.