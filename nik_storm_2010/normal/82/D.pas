uses math;
type dp=record x,y,q,w,res:longint; u:boolean; end; qu=record x,y:longint; end;
const l=1010;
var
  f:array[0..l,0..l] of dp; q:array[1..l*l] of qu; a:array[0..l] of longint;
  out:array[1..2,0..l] of longint; leng,st,fn,n,i,j,x,y:longint;


procedure addq(a,b:longint);
begin
  f[a,b].u:=true; q[fn].x:=a; q[fn].y:=b;
  inc(fn);
end;


procedure outq(var a,b:longint);
begin
  a:=q[st].x; b:=q[st].y;
  inc(st);
end;


procedure modify(x1,y1,x2,y2,o,p:longint);
begin
  if f[x1,y1].res+max(a[o],a[p])<f[x2,y2].res then
  begin
    f[x2,y2].res:=f[x1,y1].res+max(a[o],a[p]);
    f[x2,y2].x:=x1; f[x2,y2].y:=y1;
    f[x2,y2].q:=o; f[x2,y2].w:=p;
    if f[x2,y2].u=false then addq(x2,y2);
  end;
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  for i:=0 to l do for j:=0 to l do f[i,j].res:=maxlongint;
  st:=1; fn:=1; f[0,1].res:=0; addq(0,1);
  while st<>fn do
  begin
    outq(x,y); if (x=0) and (y=n+1) then break;
    if x=0 then
    begin
      if y=n then modify(x,y,0,n+1,y,0) else
      if y=n-1 then modify(x,y,0,n+1,y,y+1) else
      begin
        modify(x,y,0,y+2,y,y+1);
        modify(x,y,y+1,y+3,y,y+2);
        modify(x,y,y,y+3,y+1,y+2);
      end;
    end
      else
    begin
      if y=n+1 then modify(x,y,0,n+1,x,0) else
      if y=n then modify(x,y,0,n+1,x,y) else
      begin
        modify(x,y,0,y+1,x,y);
        modify(x,y,y,y+2,x,y+1);
        modify(x,y,x,y+2,y,y+1);
      end;
    end;
  end;
  writeln(f[0,n+1].res); i:=0; j:=n+1; leng:=(n+1) div 2;
  while not((i=0)and(j=0)) do
  begin
    out[1,leng]:=f[i,j].q; out[2,leng]:=f[i,j].w; dec(leng);
    x:=f[i,j].x; y:=f[i,j].y;
    i:=x; j:=y;
  end;
  for i:=1 to (n+1) div 2 do
  begin
    write(out[1,i],' ');
    if out[2,i]<>0 then writeln(out[2,i]);
  end;

end.