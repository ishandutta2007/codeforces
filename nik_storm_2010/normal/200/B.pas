var i,sum,c,n:longint; ans:real;
 begin
  readln(n);
   for i:=1 to n do
    begin
     read(c); sum:=sum+c;
    end;
  ans:=sum/n; writeln(ans:0:4);
 end.