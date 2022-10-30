program storm;
var x,y,ch:longint;
    ras:extended;


procedure inputdata;
begin
 readln(x,y);
end;

procedure outputdata(priz:longint);
begin
 if priz=1 then writeln('black')
           else writeln('white');
end;

begin
 inputdata;
 if (x=0)  or (y=0) then begin outputdata(1); halt; end;
 ras:=sqrt(x*x+y*y);
   if ((x>0) and (y>0)) or ((x<0) and (y<0)) then
     begin
     if trunc(ras)=ras then begin outputdata(1); halt; end;
     ch:=trunc(ras);
     if ch mod 2 = 0 then begin outputdata(1); halt; end
                     else begin outputdata(0); halt; end;

     end
                                             else
     begin
     if trunc(ras)=ras then begin outputdata(1); halt; end;
     ch:=trunc(ras);
     if ch mod 2 = 0 then begin outputdata(0); halt; end
                     else begin outputdata(1); halt; end;
     end;
end.