uses math;
var
 coor:array[1..2,1..10000] of longint;
  used:array[1..10000] of boolean;
   kol,xa,xb,ya,yb,i,answer,n:longint;



procedure preparation;
var i:longint;
 begin
  kol:=0;
   for i:=min(xa,xb) to max(xa,xb) do
    begin
     inc(kol);
      coor[1,kol]:=i;
     coor[2,kol]:=ya;
     inc(kol);
      coor[1,kol]:=i;
     coor[2,kol]:=yb;
    end;
   for i:=min(ya,yb)+1 to max(ya,yb)-1 do
    begin
     inc(kol);
      coor[1,kol]:=xa;
     coor[2,kol]:=i;
     inc(kol);
      coor[1,kol]:=xb;
     coor[2,kol]:=i;
    end;
 end;


procedure processdata;
var i,j,x,y,r:longint;
 begin
  readln(xa,ya,xb,yb);
   preparation;
  readln(n);
   for i:=1 to n do
    begin
     readln(x,y,r);
      for j:=1 to kol do
       if (r * r) >= ( sqr(coor[1,j]-x) + sqr(coor[2,j]-y) ) then used[j]:=true;
    end;
 end;


begin

  processdata;
   answer:=0;
    for i:=1 to kol do
   if used[i] = false then inc(answer);
  writeln(answer);

end.