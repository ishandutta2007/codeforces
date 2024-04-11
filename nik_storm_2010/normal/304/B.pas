const months:array[1..12] of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
var
    s1,s2:string; k1,k2,dd1,dd2,mm1,mm2,yy1,yy2,code,dd,mm,yy,k:longint;


function high(year:longint):boolean;
begin
  if (year mod 4<>0) then high:=false else
  if (year mod 100<>0) then high:=true else
  if (year mod 400=0)  then high:=true else high:=false;
end;


begin

  readln(s1); val(copy(s1,9,2),dd1,code); val(copy(s1,6,2),mm1,code); val(copy(s1,1,4),yy1,code);
  readln(s2); val(copy(s2,9,2),dd2,code); val(copy(s2,6,2),mm2,code); val(copy(s2,1,4),yy2,code);
  dd:=1; mm:=1; yy:=1900; k:=1; k1:=1; k2:=1;
  while not((dd=1)and(mm=1)and(yy=2040)) do
    begin
      inc(dd); inc(k);
      if (dd>months[mm]) then
        begin
          if (dd=29) and (mm=2) and (high(yy)=true) then else
            begin
              dd:=1; inc(mm);
              if mm=13 then begin inc(yy); mm:=1; end;
            end;
        end;
      if (dd1=dd) and (mm1=mm) and (yy1=yy) then k1:=k;
      if (dd2=dd) and (mm2=mm) and (yy2=yy) then k2:=k;
    end;
  writeln(abs(k1-k2));

end.