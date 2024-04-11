var
  h1,h2,m1,m2,t1,t2,code:longint;
  s:string;

begin
  readln(s);
  val(copy(s,1,2),h1,code);
  val(copy(s,4,2),m1,code);
  t1:=h1*60+m1;
  readln(s);
  val(copy(s,1,2),h2,code);
  val(copy(s,4,2),m2,code);
  t2:=h2*60+m2;
  t1:=t1-t2;
  if (t1<0) then t1:=t1+24*60;
  h1:=t1 div 60;
  m1:=t1 mod 60;
  if (h1<10) then write('0');
  write(h1);
  write(':');
  if (m1<10) then write('0');
  write(m1);
end.