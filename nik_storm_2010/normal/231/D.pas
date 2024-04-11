var
    sum,x1,y1,z1,a1,a2,a3,a4,a5,a6,x,y,z:longint;


begin

  readln(x,y,z); readln(x1,y1,z1);
  readln(a1,a2,a3,a4,a5,a6); sum:=0;
  if y<0  then sum:=sum+a1;
  if y>y1 then sum:=sum+a2;
  if z<0  then sum:=sum+a3;
  if z>z1 then sum:=sum+a4;
  if x<0  then sum:=sum+a5;
  if x>x1 then sum:=sum+a6;
  writeln(sum);

end.