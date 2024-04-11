Var
    a: array[1..5] of int64;
     s: array[1..4] of char;
      used: array[1..4] of boolean;
       min: int64;


procedure rec(nom:longint);
var i,j:longint;
     c: int64;
 begin
  if nom=4
   then
    begin
     for i:=1 to 4 do
      if (used[i]=false)
       then c:=a[i];
     if c<min
      then min:=c;
    end
   else
    begin
     for i:=1 to 4 do
      for j:=i+1 to 4 do
       if (used[i]=false) and (used[j]=false)
        then
         begin
          if s[nom] = '*'
           then
            begin
             used[j]:=true;
              if a[j]=0
               then c:=a[i];
                a[i]:=a[i] * a[j];
                 rec(nom+1);
                if a[j]=0
                 then a[i]:=c
                  else a[i]:=a[i] div a[j];
             used[j]:=false;
            end
           else
            begin
             used[j]:=true;
              a[i]:=a[i] + a[j];
               rec(nom+1);
              a[i]:=a[i] - a[j];
             used[j]:=false;
            end;
         end;
    end;
 end;


Begin

  readln(a[1],a[2],a[3],a[4]);
   readln(s[1],s[4],s[2],s[4],s[3]);
    min:=1000000000000000000;
     rec(1);
  writeln(min);

End.