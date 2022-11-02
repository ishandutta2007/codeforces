const d:array[1..2,1..4] of longint=((0,1,0,-1),(1,0,-1,0));
var
    a:array[1..100000] of longint; sx,sy,x,y,n,i:longint; c:char;


function better(a,b,c,d:longint):boolean;
begin
  if abs(a-x)+abs(b-y)<abs(c-x)+abs(d-y) then better:=true else better:=false;
end;


begin

  readln(n,sx,sy,x,y);
  if (sx=x) and (sy=y) then begin writeln(0); halt; end;
  for i:=1 to n do
    begin
      read(c);
      if c='N' then a[i]:=1; if c='E' then a[i]:=2;
      if c='S' then a[i]:=3; if c='W' then a[i]:=4;
    end;
  for i:=1 to n do
    begin
      if better(sx+d[1,a[i]],sy+d[2,a[i]],sx,sy) then begin sx:=sx+d[1,a[i]]; sy:=sy+d[2,a[i]]; end;
      if (sx=x) and (sy=y) then begin writeln(i); halt; end;
    end;
  writeln(-1);

end.