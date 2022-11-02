var
   n,ost,x,y:int64;


function trg(x:int64):int64;
 begin
  trg:=(x*(x+1)) div 2;
 end;

procedure dix(need:int64; var ans:int64);
var left,right,middle:int64;
 begin
  left:=1; right:=50000;
   while right-left>1 do
    begin
     middle:=(left+right) div 2;
      if trg(middle) > need
      then right:=middle
     else left:=middle;
    end;
  ans:=-1;
   if trg(right) = need then ans:=right;
  if trg(left) = need then ans:=left;
 end;


begin

  readln(n);
   x:=1;
  while trg(x) <= n do
   begin
    ost:=n-trg(x);
     dix(ost,y);
    if y <> -1 then
     begin
      writeln('YES');
      halt;
     end;
    inc(x);
   end;
  writeln('NO');

end.