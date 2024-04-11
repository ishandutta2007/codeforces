uses math;
var
    mas:array[1..10000000] of longint; answer,pred,a,n,x,y:int64; i:longint;


begin


  readln(a,n); for i:=1 to a+n-1 do mas[i]:=maxlongint;

  pred:=round(sqrt(a+n-1));
  for i:=2 to pred do
    begin
      x:=i*i; y:=1;
      while x*y<=a+n-1 do
        begin
          mas[x*y]:=min(mas[x*y],y);
          inc(y);
        end;
    end;

  answer:=0; for i:=a to a+n-1 do
    if mas[i]=maxlongint then answer:=answer+i else answer:=answer+mas[i];
  writeln(answer);

end.