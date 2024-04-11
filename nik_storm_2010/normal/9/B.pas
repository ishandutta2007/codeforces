Var
    a: array[1..100] of longint;
     n,vbus,vstudent,minnom,xuniversity,yuniversity,nom: int64;
      mintime,time: extended;
       i: longint;


Begin

  readln(n,vbus,vstudent);
   for i:=1 to n do read(a[i]);
   readln;
  readln(xuniversity,yuniversity);

  mintime:=1000000000;
   for i:=2 to n do
    begin

      time:=(a[i]/vbus) + ( sqrt(sqr(a[i]-xuniversity)+sqr(yuniversity)) / vstudent);
       if time <= mintime
        then
         begin
          mintime:=time;
           nom:=i;
         end;

    end;
  writeln(nom);

End.