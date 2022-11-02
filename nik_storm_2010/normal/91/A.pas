Var
    letter: array[97..122,0..10000] of integer;
     leng,i,nom,right,left,middle,pred,answer: longint;
      s: ansistring;


Begin

  readln(s);
   leng:=length(s);
    for i:=1 to leng do
     begin
      nom:=ord(s[i]);
       inc(letter[nom,0]);
        letter[nom,letter[nom,0]]:=i;
     end;

  answer:=1;
   pred:=0;
    readln(s);
     leng:=length(s);
      for i:=1 to leng do
       begin
        nom:=ord(s[i]);
         if letter[nom,0] = 0
          then
           begin
            writeln(-1);
             halt;
           end;
        left:=1; right:=letter[nom,0];
         while right-left>1 do
          begin
           middle:=(left+right) div 2;
            if letter[nom,middle] > pred then right:=middle else left:=middle;
          end;
        if letter[nom,left] > pred then pred:=letter[nom,left] else
         if letter[nom,right] > pred then pred:=letter[nom,right]
          else
           begin
            inc(answer);
             pred:=letter[nom,1];
           end;
       end;
  writeln(answer);

End.