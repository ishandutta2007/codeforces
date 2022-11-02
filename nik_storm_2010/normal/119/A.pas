var
    a,b,c,n : longint;


function nod(a,b:longint) : longint;
 begin
  while (a<>0) and (b<>0) do
   if a>b then a:=a mod b
           else b:=b mod a;
  exit(a+b);
 end;


Begin

  readln(a,b,c);
   while true do
    begin
     n:=nod(a,c);
      if c >= n
       then
        c:=c-n
       else
        begin
         writeln(1);
          halt;
        end;
     n:=nod(b,c);
      if c >= n
       then
        c:=c-n
       else
        begin
         writeln(0);
          halt;
        end;
    end;

End.