var
    a: array[1..100000] of int64;
     step,n,x,y: int64;
      i:longint;


Begin

  readln(n,x,y);
   for i:=1 to n-1 do
    begin
     a[i]:=1;
      if y>0
       then dec(y)
       else
        begin
         writeln(-1);
          halt;
        end;
    end;

  if y = 0
   then
    begin
     writeln(-1);
      halt;
    end
   else
    a[n]:=y;

  step:=0;
   for i:=1 to n do
    step:=step+a[i]*a[i];

  if step>=x
   then
    begin
     for i:=1 to n do
      writeln(a[i])
    end
   else
    begin
     writeln(-1);
    end;

End.