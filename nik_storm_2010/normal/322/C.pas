uses math;
var
  x,y,a,b,l,r,m:int64; d,i:longint; may:boolean; s:string;


function better(ii,jj:int64):boolean;
var x1,x2,y1,y2:int64;
begin
  x1:=ii*x; y1:=ii*y;
  x2:=jj*x; y2:=jj*y;
  if abs(x1-a)+abs(y1-b) < abs(x2-a)+abs(y2-b) then better:=true else better:=false;
end;


function good(coef:int64):boolean;
var xx,yy:int64; i:longint;
begin
  xx:=coef*x; yy:=coef*y;
  if (xx=a) and (yy=b) then exit(true);
  for i:=1 to d do
  begin
    if s[i]='R' then xx:=xx+1;
    if s[i]='U' then yy:=yy+1;
    if s[i]='L' then xx:=xx-1;
    if s[i]='D' then yy:=yy-1;
    if (xx=a) and (yy=b) then exit(true);
  end;
  good:=false;
end;


begin

  readln(a,b); readln(s);
  d:=length(s);
  x:=0; y:=0;
  for i:=1 to d do
  begin
    if s[i]='R' then x:=x+1;
    if s[i]='U' then y:=y+1;
    if s[i]='L' then x:=x-1;
    if s[i]='D' then y:=y-1;
  end;
  if (x=0) and (y=0) then
  begin
    may:=good(0);
    if may=true then writeln('Yes') else writeln('No');
    halt;
  end;
  l:=0; r:=2000000000;
  while r-l>1 do
  begin
    m:=(r+l) div 2;
    if better(m-1,m+1) then r:=m else l:=m;
  end;
  for i:=max(0,l-200) to l+200 do
    if good(i) then
    begin
      writeln('Yes');
      halt;
    end;
  writeln('No');

end.