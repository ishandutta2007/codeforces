uses math;
 var
   dx, dy, n, m, x, y, k, kol1, kol2, kol, answer : int64;
    i : longint;


procedure find(directory:char; var kol:int64);
var ras:int64;
 begin
  if directory = 'x'
   then
    begin
     if dx=0 then begin kol:=maxlongint; exit; end;
      if dx>0
       then
        begin
         ras:=n-x;
         kol:=ras div dx;
        end
       else
        begin
         ras:=x-1;
         kol:=ras div abs(dx);
        end;
    end
   else
    begin
     if dy=0 then begin kol:=maxlongint; exit; end;
      if dy>0
       then
        begin
         ras:=m-y;
         kol:=ras div dy;
        end
       else
        begin
         ras:=y-1;
         kol:=ras div abs(dy);
        end;
    end;
 end;


begin

  readln(n,m);
   readln(x,y);
  readln(k);

  for i:=1 to k do
   begin
    readln(dx,dy);
     find('x',kol1);
    find('y',kol2);

    kol:=min(kol1,kol2);

    x:=x + dx*kol;
     answer:=answer + kol;
    y:=y + dy*kol;

   end;
  writeln(answer);

end.