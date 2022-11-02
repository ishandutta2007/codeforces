const d:array[1..2,1..4] of longint=((1,-1,0,0),(0,0,-1,+1));
var
  a:array[0..1001,0..1001] of char; u:array[0..1001,0..1001] of boolean;
  r,c,i,j,st,fn,xx,yy,x1,y1,x2,y2,pp,code,ans,leng,ras:longint; q:array[1..3,1..10000000] of longint;


procedure add(x,y,z:longint);
begin
  u[x,y]:=true;
  q[1,fn]:=x; q[2,fn]:=y; q[3,fn]:=z;
  inc(fn);
end;


procedure out(var x,y,z:longint);
begin
  x:=q[1,st]; y:=q[2,st]; z:=q[3,st];
  inc(st);
end;


begin

  for i:=0 to 1001 do for j:=0 to 1001 do a[i,j]:='T';
  readln(r,c);
  for i:=1 to r do
  begin
    for j:=1 to c do read(a[i,j]);
    readln;
  end;
  for i:=1 to r do
    for j:=1 to c do
    begin
      if a[i,j]='E' then
      begin
        x1:=i; y1:=j;
      end;
      if a[i,j]='S' then
      begin
        x2:=i; y2:=j;
      end;
    end;
  st:=1; fn:=1; add(x1,y1,0); leng:=0;
  while st<>fn do
  begin
    out(xx,yy,ras);
    if (xx=x2) and (yy=y2) then begin leng:=ras; break; end;
    for i:=1 to 4 do
      if (a[xx+d[1,i],yy+d[2,i]]<>'T') and (u[xx+d[1,i],yy+d[2,i]]=false) then
      begin
        add(xx+d[1,i],yy+d[2,i],ras+1);
      end;
  end;
  ans:=0;
  fillchar(u,sizeof(u),false);
  st:=1; fn:=1; add(x1,y1,0);
  while st<>fn do
  begin
    out(xx,yy,ras);
    if (ras<=leng) and (a[xx,yy] in ['1'..'9']) then begin val(a[xx,yy],pp,code); ans:=ans+pp; end;
    for i:=1 to 4 do
      if (a[xx+d[1,i],yy+d[2,i]]<>'T') and (u[xx+d[1,i],yy+d[2,i]]=false) then
      begin
        add(xx+d[1,i],yy+d[2,i],ras+1);
      end;
  end;
  writeln(ans);

end.