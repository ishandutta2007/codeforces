Var
    a: array[1..3,1..100000] of longint;
     l,b,f,n,i,koef,r,allcar,coor: longint;



procedure poisk_position(leng,nomcar:longint; var coor:longint);
var i,j : longint;
 begin

   if allcar = 0
    then
     begin
      if l>=leng
       then
        begin
         inc(allcar);
          a[1,allcar]:=0;
           a[2,allcar]:=leng;
            a[3,allcar]:=nomcar;
         coor:=0;
          exit;
        end
       else
        begin
         coor:=-1;
          exit;
        end;
     end;
   if a[1,1]-f>=leng
    then
     begin
      for i:=allcar+1 downto 2 do
       begin
        a[1,i]:=a[1,i-1];
         a[2,i]:=a[2,i-1];
          a[3,i]:=a[3,i-1];
       end;
      inc(allcar);
       a[1,1]:=0;
        a[2,1]:=leng;
         a[3,1]:=nomcar;
      coor:=0;
       exit;
     end;

  for i:=1 to allcar-1 do
   if a[1,i+1] - a[2,i] >= leng+b+f
    then
     begin
      for j:=allcar+1 downto i+2 do
       begin
        a[1,j]:=a[1,j-1];
         a[2,j]:=a[2,j-1];
          a[3,j]:=a[3,j-1];
       end;
      inc(allcar);
       a[1,i+1]:=a[2,i]+b;  coor:=a[2,i]+b;
        a[2,i+1]:=a[1,i+1]+leng;
         a[3,i+1]:=nomcar;
      exit;
     end;

   if l-a[2,allcar] >= leng+b
    then
     begin
      inc(allcar);
       a[1,allcar]:=a[2,allcar-1]+b;
        a[2,allcar]:=a[1,allcar]+leng;
         a[3,allcar]:=nomcar;
       coor:=a[1,allcar];
        exit
     end
    else
     begin
      coor:=-1;
       exit;
     end;

 end;


procedure car_exit(nom:longint);
var i,j:longint;
 begin
  for i:=1 to allcar do
   if a[3,i] = nom
    then
     begin
      for j:=i+1 to allcar do
       begin
        a[1,j-1]:=a[1,j];
         a[2,j-1]:=a[2,j];
          a[3,j-1]:=a[3,j];
       end;
     end;
  dec(allcar);
 end;


Begin

  readln(l,b,f);
   readln(n); allcar:=0;
    for i:=1 to n do
     begin

       readln(koef,r);
        if koef = 1
         then
          begin

            poisk_position(r,i,coor);
             writeln(coor);

          end
         else
          begin

            car_exit(r);

          end;

     end;

End.