program storm;
uses math;
var n,x1,x2,y1,y2,A,B,ras:longint;


procedure inputdata;
begin
 readln(n,x1,y1,x2,y2);
end;

procedure outputdata;
begin
 writeln(ras);
end;

procedure naiti_a;
begin
 if (x1=0)  then A:=1;
 if (y1=n)  then A:=2;
 if (x1=n)  then A:=3;
 if (y1=0)  then A:=4;
end;

procedure naiti_b;
begin
 if (x2=0)  then B:=1;
 if (y2=n)  then B:=2;
 if (x2=n)  then B:=3;
 if (y2=0)  then B:=4;
end;

begin
 inputdata; naiti_a; naiti_b; ras:=0;
 if      (A=B)      then begin ras:=abs(y1-y2)+abs(x1-x2); outputdata; halt; end;
 if (A=1) and (B=2) then begin ras:=abs(y1-n)+abs(x1-x2); outputdata; halt; end;
 if (A=1) and (B=3) then begin ras:=min(n-y1+n+n-y2,y1+n+y2); outputdata; halt; end;
 if (A=1) and (B=4) then begin ras:=y1+x2; outputdata; halt; end;

 if (A=2) and (B=1) then begin ras:=x1+n-y2; outputdata; halt; end;
 if (A=2) and (B=4) then begin ras:=min(n-x1+n+n-x2,x1+n+x2); outputdata; halt; end;
 if (A=2) and (B=3) then begin ras:=n-x1+n-y2; outputdata; halt; end;

 if (A=3) and (B=2) then begin ras:=n-y1+n-x2; outputdata; halt; end;
 if (A=3) and (B=1) then begin ras:=min(n-y1+n+n-y2,y1+n+y2); outputdata; halt; end;
 if (A=3) and (B=4) then begin ras:=y1+n-x2; outputdata; halt; end;

 if (A=4) and (B=2) then begin ras:=min(n-x1+n+n-x2,x1+n+x2); outputdata; halt; end;
 if (A=4) and (B=3) then begin ras:=n-x1+y2; outputdata; halt; end;
 if (A=4) and (B=1) then begin ras:=x1+y2; outputdata; halt; end;
end.