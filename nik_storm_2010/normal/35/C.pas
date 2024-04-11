Var
    a: array[1..2000,1..2000] of longint;
     fire: array[1..2,1..10] of longint;
      n,m,k,i,j,min,maxras,ansx,ansy,y: longint;



Begin

  assign(input,'input.txt'); reset(input);
   assign(output,'output.txt'); rewrite(output);

  readln(n,m);
   readln(k);
    for i:=1 to k do read(fire[1,i],fire[2,i]);

  maxras:=-1;
   for i:=1 to n do
    for j:=1 to m do
     begin
      min:=MaxLongint;
       for y:=1 to k do
        if (abs(i-fire[1,y]) + abs(j-fire[2,y])) < min then min:=(abs(i-fire[1,y]) + abs(j-fire[2,y]));
      if min > maxras
       then
        begin
         maxras:=min;
          ansx:=i;
           ansy:=j;
        end;
     end;
  writeln(ansx,' ',ansy);
   close(input); close(output);

End.