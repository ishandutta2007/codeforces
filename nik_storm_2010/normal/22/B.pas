Uses
   math;
Var
   a: array[1..25,1..25] of char;
    i,j,x,y,n,m,maxp: longint;
     priz: boolean;



procedure proverka(i,j,l,r:longint; var priz:boolean);
var t1,t2:longint;
 begin

   priz:=true;

    for t1:=i to i+l-1 do
     for t2:=j to j+r-1 do
      if a[t1,t2] = '1'
       then
        begin
         priz:=false;
          break;
        end;

 end;


Begin

  readln(n,m);
   for i:=1 to n do
    begin
     for j:=1 to m do read(a[i,j]);
      readln;
    end;

  maxp:=-1;
   for i:=1 to n do
    for j:=1 to m do
     begin

       for x:=1 to n-i+1 do
        for y:=1 to m-j+1 do
         begin

           proverka(i,j,x,y,priz);
            if priz = true then maxp:=max((x+y)*2, maxp);

         end;

     end;
  writeln(maxp);

End.