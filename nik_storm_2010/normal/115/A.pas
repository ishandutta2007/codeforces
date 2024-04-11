var
    main: array[1..2000] of longint;
    g: array[1..2000,1..2000] of longint;
    ch,n,i,answer,priz,j,y: longint;
    gr: array[1..2000,0..2000] of longint;
    pri: boolean;


procedure rec(nom:longint);
var i:longint;
 begin
  for i:=1 to n do
   if (main[i] = nom) and (i<>nom)
    then
     begin
      g[i]:=g[nom];
       g[i,nom]:=1;
        rec(i);
     end;

 end;


Begin

  readln(n);
   for i:=1 to n do
    readln(main[i]);

  for i:=1 to n do
   if main[i] = -1
    then
     begin
      rec(i);
     end;

  answer:=0;
   for i:=1 to n do
    begin
     pri:=false;
      for j:=1 to answer do
       begin

        priz:=1;
         for y:=1 to gr[j,0] do
          if (g[i,gr[j,y]] = 1) or (g[gr[j,y],i] = 1)
           then
            begin
             priz:=0;
              break;
            end;

        if priz = 1
         then
          begin
           pri:=true;
            inc(gr[j,0]);
             gr[j,gr[j,0]]:=i;
              break;
          end;
       end;
      if pri = false
       then
        begin
         inc(answer);
          gr[answer,0]:=1;
           gr[answer,1]:=i;
        end;

     end;

  writeln(answer);

End.