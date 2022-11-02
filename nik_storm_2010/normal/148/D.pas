var
  f:array[0..1000,0..1000] of extended; win,con,whi,bla:extended;
  w,b,i,j:longint;


function ans(w,b:longint):extended;
var win,con,x,y:extended;
begin
  if (w<=0) then exit(0);
  if (b<=0) then exit(1);
  if (f[w,b]<>-1) then exit(f[w,b]);
  win:=w/(w+b); con:=b/(w+b);
  con:=con*(b-1)/(w+b-1);
  if (con>=1e-10) then
  begin
    x:=ans(w,b-3)*((b-2)/(w+b-2));
    y:=ans(w-1,b-2)*(w/(w+b-2));
    win:=win+con*(x+y);
  end;
  f[w,b]:=win;
  exit(win);
end;


begin
  for i:=0 to 1000 do for j:=0 to 1000 do f[i,j]:=-1;
  readln(w,b);
  writeln(ans(w,b):0:9);
end.