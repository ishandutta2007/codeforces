const m:array[1..2,1..4] of longint=((1,-1,0,0),(0,0,1,-1));
var
  a:array[-300..300,-300..300] of longint; used:array[-300..300,-300..300] of boolean;
  q:array[1..2,1..1000000] of longint; st,fi,nx,ny,x,y,n,t,i,u:longint;


procedure addq(x,y:longint);
begin
  q[1,fi]:=x; q[2,fi]:=y; inc(fi);
  if fi>1000000 then fi:=1;
end;


procedure outq(var x,y:longint);
begin
  x:=q[1,st]; y:=q[2,st]; inc(st);
  if st>1000000 then st:=1;
end;


begin

  readln(n,t); st:=1; fi:=1; addq(0,0); a[0,0]:=n;
  while st<>fi do
  begin
    outq(x,y); used[x,y]:=false;
    if a[x,y]>=4 then
    begin
      u:=a[x,y] div 4; a[x,y]:=a[x,y] mod 4;
      for i:=1 to 4 do
      begin
        nx:=x+m[1,i]; ny:=y+m[2,i]; a[nx,ny]:=a[nx,ny]+u;
        if used[nx,ny]=false then begin addq(nx,ny); used[nx,ny]:=true; end;
      end;
    end;
  end;
  for i:=1 to t do
  begin
    readln(x,y);
    if (abs(x)<=300) and (abs(y)<=300) then writeln(a[x,y]) else writeln(0);
  end;

end.