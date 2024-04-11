var
    nam: array[1..16] of string;
    g: array[1..16,1..16] of longint;
    tekkom: array[1..16] of longint;
    sanswer: array[1..16] of string;
    b: array[1..16] of longint;
    j,i,y,n,k,nom1,nom2,maxkol: longint;
    s,stek: string;



procedure rec(nom:longint);
var i,tekkol:longint;
 begin
   if nom = n+1
    then
     begin
      tekkol:=0;
       for i:=1 to n do
        if b[i] = 1 then
         begin
          inc(tekkol);
           for j:=i+1 to n do
            if (b[j]=1) and (g[i,j] = 1) then exit;
         end;
      if maxkol < tekkol
       then
        begin
         maxkol:=tekkol;
          for i:=1 to 16 do tekkom[i]:=b[i];
        end;

     end
    else
     begin
      for i:=0 to 1 do
       begin
        b[nom]:=i;
         rec(nom+1);
        b[nom]:=0;
       end;
     end;

 end;


Begin

  readln(n,k);
   for i:=1 to n do readln(nam[i]);
    for i:=1 to k do
     begin
      readln(s);
       j:=1;
        while s[j] <> ' ' do inc(j);
         stek:=copy(s,1,j-1);
          for y:=1 to n do
           if nam[y] = stek then
            begin
             nom1:=y;
              break;
            end;
         stek:=copy(s,j+1,length(s)-j);
          for y:=1 to n do
           if nam[y] = stek then
            begin
             nom2:=y;
              break;
            end;
       g[nom1,nom2]:=1;
        g[nom2,nom1]:=1;
     end;

  maxkol:=0;
   rec(1);

  maxkol:=0;
   for i:=1 to n do
    if tekkom[i] = 1
     then
      begin
       inc(maxkol);
        sanswer[maxkol]:=nam[i];
      end;

  for i:=1 to maxkol-1 do
   for j:=1 to maxkol-1 do
    if sanswer[j] > sanswer[j+1]
     then
      begin
       stek:=sanswer[j];
        sanswer[j]:=sanswer[j+1];
         sanswer[j+1]:=stek;
      end;

  writeln(maxkol);
   for i:=1 to maxkol do
    writeln(sanswer[i]);

End.