var
  x,y : array[1..8] of longint;
   m1,m2 : array[1..4] of longint;
    kol1,kol2,kolras,i : longint;
     used: array[1..8] of boolean;
      ras : array[1..100] of extended;
       kol : array[1..100] of longint;
        mastek : array[1..3] of extended;





procedure rec(tek:longint);
var i,j,p,koll,p1,p2,nom : longint;
     tekras,max : extended;
      priz,prizadd : boolean;
 begin

   if tek=9
    then
     begin

       kolras:=0;
        for i:=1 to 4 do
         for j:=1 to 4 do
          if i<>j
           then
            begin

              tekras:=sqrt( sqr(x[m1[i]]-x[m1[j]]) + sqr(y[m1[i]]-y[m1[j]]) );
               priz:=false;
                for p:=1 to kolras do
                 if ras[p]=tekras
                  then
                   begin
                    priz:=true;
                     inc(kol[p]);
                    break;
                   end;
              if priz=false
               then
                begin
                 inc(kolras);
                  ras[kolras]:=tekras;
                 kol[kolras]:=1;
                end;

            end;
       if (kolras=2) and ((kol[1]=4) and (kol[2]=8)) or ((kol[1]=8) and (kol[2]=4))
        then kolras:=0
         else exit;

       kolras:=0; prizadd:=false;
        for i:=1 to 4 do
         begin
          koll:=0; fillchar(mastek,sizeof(mastek),0);
         for j:=1 to 4 do
          if i<>j
           then
            begin


              tekras:=sqrt( sqr(x[m2[i]]-x[m2[j]]) + sqr(y[m2[i]]-y[m2[j]]) );
               inc(koll); mastek[koll]:=tekras;
               priz:=false;
                for p:=1 to kolras do
                 if ras[p]=tekras
                  then
                   begin
                    priz:=true;
                     inc(kol[p]);
                    break;
                   end;
              if priz=false
               then
                begin
                 inc(kolras);
                  ras[kolras]:=tekras;
                 kol[kolras]:=1;
                end;

            end;
             for p1:=1 to 3 do
              for p2:=p1+1 to 3 do
               if mastek[p1]=mastek[p2] then prizadd:=true;
            end;

           max:=0; nom:=1000;
         for i:=1 to kolras do
          if max<ras[i] then
           begin
            max:=ras[i];
             nom:=i;
           end;

         if ((kolras=2) and ((kol[1]=4) and (kol[2]=8)) or ((kol[1]=8) and (kol[2]=4))) or ((kolras=3) and (kol[nom]=4) and (prizadd=false))
          then
           begin

             writeln('YES');
              writeln(m1[1],' ',m1[2],' ',m1[3],' ',m1[4]);
             writeln(m2[1],' ',m2[2],' ',m2[3],' ',m2[4]);
              halt;

           end
           else exit;


     end
    else
     begin

       for i:=1 to 8 do
        if used[i]=false
         then
          begin

            used[i]:=true;
             if kol1<4
              then
               begin

                 inc(kol1);
                  m1[kol1]:=i;
                   rec(tek+1);
                  m1[kol1]:=0;
                 dec(kol1);

               end
              else
               begin

                 inc(kol2);
                  m2[kol2]:=i;
                   rec(tek+1);
                  m2[kol2]:=0;
                 dec(kol2);

               end;
             used[i]:=false;

          end;

     end;

 end;




begin

  for i:=1 to 8 do readln(x[i],y[i]);

    kol1:=0; kol2:=0;
     rec(1);

  writeln('NO');

end.