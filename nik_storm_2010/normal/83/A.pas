program A83;
var
   a : array[1..100000] of longint;
   n,i,pred,j : longint;
   answer : int64;


Begin

  readln(n);
   for i:=1 to n do read(a[i]);

  answer:=0;
   pred:=MaxLongint;
    for i:=1 to n do
     if a[i] = pred
      then
       begin

         inc(j);
         answer:=answer+j;

       end
      else
       begin

         j:=1;
         pred:=a[i];
         answer:=answer+j;

       end;

  writeln(answer);

End.