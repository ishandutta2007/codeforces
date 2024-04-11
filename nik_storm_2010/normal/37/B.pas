uses math;
var
 a,ans:array[1..2,1..1000] of longint;
  used:array[1..1000] of boolean; answer:boolean;
   n,health,maxhealth,damage,reg,kol,time,i,nom:longint;


procedure poisk(var answer:boolean; var nom:longint);
var dam,i:longint;
     percent:extended;
 begin
  dam:=0;
   percent:=health/maxhealth*100;
    for i:=1 to n do
     if (used[i]=false) and (percent<=a[1,i]) and (a[2,i]>dam)
      then
       begin
        nom:=i;
        dam:=a[2,i];
       end;
  if dam=0
   then
    begin
     answer:=false;
    end
   else
    begin
     used[nom]:=true;
     answer:=true;
    end;
 end;


begin

  readln(n,maxhealth,reg);
   for i:=1 to n do
    begin
     readln(a[1,i],a[2,i]);
     used[i]:=false;
    end;
  time:=0;
   damage:=0; health:=maxhealth;
    while true do
     begin
      poisk(answer,nom);
       if (answer=false) and (damage<=reg)
        then
         begin
          writeln('NO');
           halt;
         end;
       if (answer=true)
        then
         begin
          inc(kol);
           ans[1,kol]:=time;
           ans[2,kol]:=nom;
          damage:=damage+a[2,nom];
         end;
       inc(time);
        health:=health-damage;
       health:=min(maxhealth,health+reg);
       if health<=0
        then
         begin
          writeln('YES');
           writeln(time,' ',kol);
            for i:=1 to kol do writeln(ans[1,i],' ',ans[2,i]);
           halt;
         end;
     end;

end.