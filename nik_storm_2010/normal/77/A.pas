Const
    nameheroes : array[1..7] of string = ('Anka','Chapay','Cleo','Troll','Dracul','Snowy','Hexadecimal');
Var
    g: array[1..7,1..7] of longint;
     e: array[1..3] of longint;
      group: array[1..3,0..7] of longint;
       n,i,j,nom1,nom2,answer,friends: longint;
        s,s1,s2: string;



procedure rec(nom:longint);
var i,j,y,maxexp,minexp,tekexp,tekfriends:longint;
 begin
  if nom = 8
   then
    begin

      if (group[1,0]=0) or (group[2,0]=0) or (group[3,0]=0) then exit;

      tekfriends:=0; maxexp:=0; minexp:=MaxLongint;
       for i:=1 to 3 do
        begin
         for j:=1 to group[i,0] do
          for y:=1 to group[i,0] do
           inc(tekfriends,g[group[i,j],group[i,y]]);

         tekexp:=e[i] div group[i,0];
          if tekexp > maxexp then maxexp:=tekexp;
           if tekexp < minexp then minexp:=tekexp;
        end;

      if ((maxexp-minexp) < answer) or ((maxexp-minexp = answer) and (tekfriends>friends))
       then
        begin
         answer:=maxexp-minexp;
          friends:=tekfriends;
        end;

    end
   else
    begin

      for i:=1 to 3 do
       begin
        inc(group[i,0]);
         group[i,group[i,0]]:=nom;
          rec(nom+1);
         group[i,group[i,0]]:=0;
        dec(group[i,0]);
       end;

    end;
 end;


Begin

  readln(n);
   for i:=1 to n do
    begin
     readln(s);
      s1:=''; s2:='';
       j:=1;
        while s[j]<>' ' do
         begin
          s1:=s1+s[j];
           inc(j);
         end;
       j:=length(s);
        while s[j]<>' ' do
         begin
          s2:=s[j]+s2;
           dec(j);
         end;
      for j:=1 to 7 do
       begin
        if nameheroes[j] = s1 then nom1:=j;
        if nameheroes[j] = s2 then nom2:=j;
       end;
     g[nom1,nom2]:=1;
    end;
   readln(e[1],e[2],e[3]);

  answer:=MaxLongint; friends:=0;
   rec(1);
  writeln(answer,' ',friends);

End.