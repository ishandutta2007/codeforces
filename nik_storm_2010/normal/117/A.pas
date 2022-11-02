program A117;
var
  ans:array[1..100000] of longint;
  n,i,m,a,b,c,ga,gb,kol,divv,modd,gkol:longint;


Begin

  kol:=0;
  readln(n,m);
   for i:=1 to n do
    begin

      inc(kol);
      readln(a,b,c);
      if a=b then ans[kol]:=c;
      if a<b
       then
        begin
         ga:=a-1; gb:=b-1;
          divv:=c div ((m-1)*2);
           modd:=c mod ((m-1)*2);
            if modd>ga then inc(divv);
             ans[kol]:=divv*((m-1)*2)+gb;
        end;
      if a>b
       then
        begin
         ga:=m*2-a-1; gb:=b-1;
          divv:=c div ((m-1)*2);
           modd:=c mod ((m-1)*2);
            if modd>ga then inc(divv);
             ans[kol]:=divv*((m-1)*2)+(m*2-b-1);

        end;

    end;
  for i:=1 to kol do
   writeln(ans[i]);

End.