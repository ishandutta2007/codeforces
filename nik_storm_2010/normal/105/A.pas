program A105;
var
  answerstr : array[1..50] of string;
  answerlon : array[1..50] of longint;
  ch : longint;
  k : longint;
  i1,n,m,code,t,i,kol,j : longint;
  s,s1,s2 : string;


Begin

 kol:=0;
  read(n,m); readln(s);
   val(s[4],i,t); val(s[5],i1,t);
    t:=i*10+i1;
   for i:=1 to n do
    begin
     readln(s);
      i1:=1;
       while s[i1]<>' ' do inc(i1);
        s1:=copy(s,1,i1-1);
         s2:=copy(s,i1+1,length(s)-i1);
          val(s2,k,code);
            k:=(t*k) div 100;
              if k<100
               then
               else
                begin
                 inc(kol);
                  answerstr[kol]:=s1;
                   answerlon[kol]:=k;
                end;
    end;

  for i:=1 to m do
   begin
    readln(s);
     t:=0;
      for i1:=1 to kol do
       if answerstr[i1] = s then t:=1;

     if t = 0
      then
       begin
        inc(kol);
         answerstr[kol]:=s;
          answerlon[kol]:=0;
       end;
   end;

  writeln(kol);
  for i:=1 to kol do
   for j:=i+1 to kol do
    if answerstr[i]>answerstr[j] then
     begin
      s1:=answerstr[i]; answerstr[i]:=answerstr[j]; answerstr[j]:=s1;
       t:=answerlon[i]; answerlon[i]:=answerlon[j]; answerlon[j]:=t;
     end;

     for i:=1 to kol do writeln(answerstr[i],' ',answerlon[i]);

End.