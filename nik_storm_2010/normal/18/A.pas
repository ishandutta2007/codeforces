Program A18;
Const
  mx : array[1..4] of integer = (0,1,0 ,-1);
  my : array[1..4] of integer = (1,0,-1,0 );

Var
  x1,y1,x2,y2,x3,y3 : real;
  i : longint;
  priz : boolean;


Function r(x1,y1,x2,y2:real) : real;
 Begin
  r:=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
 End;

Procedure rasst( x1,y1,x2,y2,x3,y3:real; var bol:boolean );
 Begin
  bol:=false;
  if ((x1=x2) and (y1=y2)) or ((x2=x3) and (y2=y3)) or ((x3=x1) and (y3=y1)) then exit;
  if (r(x1,y1,x2,y2))=(r(x2,y2,x3,y3))+(r(x3,y3,x1,y1)) then bol:=true;
  if (r(x2,y2,x3,y3))=(r(x1,y1,x2,y2))+(r(x3,y3,x1,y1)) then bol:=true;
  if (r(x3,y3,x1,y1))=(r(x1,y1,x2,y2))+(r(x2,y2,x3,y3)) then bol:=true;
 End;


BEGIN

  readln(x1,y1,x2,y2,x3,y3);
  rasst(x1,y1,x2,y2,x3,y3,priz);
  if priz=true then begin writeln('RIGHT'); halt; end;

  for i:=1 to 4 do
   begin
    rasst(x1+mx[i],y1+my[i],x2,y2,x3,y3,priz); if priz=true then begin writeln('ALMOST'); halt; end;
    rasst(x1,y1,x2+mx[i],y2+my[i],x3,y3,priz); if priz=true then begin writeln('ALMOST'); halt; end;
    rasst(x1,y1,x2,y2,x3+mx[i],y3+my[i],priz); if priz=true then begin writeln('ALMOST'); halt; end;
   end;

  writeln('NEITHER');

END.