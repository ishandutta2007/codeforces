uses math; const eps=0.001;
var
  x,y:array[0..3] of extended; ras:extended; may:boolean; i:longint;


procedure findcenter;
var a1,b1,c1,a2,b2,c2,a,b,c,x1,y1,x2,y2:extended;
begin
  a:=y[1]-y[2]; b:=x[2]-x[1]; c:=x[1]*y[2]-x[2]*y[1];
  x1:=(x[1]+x[2])/2; y1:=(y[1]+y[2])/2;
  a1:=-b; b1:=a;
  x2:=b1+x1;
  y2:=y1-a1;
  c1:=x1*y2-x2*y1;
  a:=y[2]-y[3]; b:=x[3]-x[2]; c:=x[2]*y[3]-x[3]*y[2];
  x1:=(x[2]+x[3])/2; y1:=(y[2]+y[3])/2;
  a2:=-b; b2:=a;
  x2:=b2+x1;
  y2:=y1-a2;
  c2:=x1*y2-x2*y1;
  x[0]:=(b1*c2-b2*c1)/(a1*b2-a2*b1);
  y[0]:=-(a1*c2-a2*c1)/(a1*b2-a2*b1);
end;


function check(i,j,n:longint):boolean;
var u1,u2:extended;
begin
  u1:=arctan2(x[i]-x[0],y[i]-y[0]);
  u2:=arctan2(x[j]-x[0],y[j]-y[0]);
  if abs(sin(n*(u1-u2)/2))<=eps then check:=true else check:=false;
end;


begin
  readln(x[1],y[1]); readln(x[2],y[2]); readln(x[3],y[3]);
  findcenter;
  ras:=sqrt(sqr(x[1]-x[0])+sqr(y[1]-y[0]));
  for i:=3 to 100 do
  begin
    may:=check(1,2,i) and check(1,3,i) and check(2,3,i);
    if may=true then
    begin
      writeln(i/2*ras*ras*sin(2*pi/i):0:6);
      break;
    end;
  end;
end.