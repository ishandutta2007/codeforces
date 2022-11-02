Var
    g: array[1..100,1..100] of longint;
     used: array[1..100] of boolean;
      n,m,i,a,b: longint;
       answer: boolean;


procedure recur(nom:longint);
var i:longint;
 begin
  used[nom]:=true;
   for i:=1 to n do
    if (g[nom,i]=1) and (not(used[i]))
     then recur(i);
 end;

Begin

  readln(n,m);
   for i:=1 to m do
    begin
     readln(a,b);
      g[a,b]:=1;
       g[b,a]:=1;
    end;

  recur(1);
   answer:=true;
    for i:=1 to n do
     if (not(used[i])) then answer:=false;

  if (answer=true) and (n=m)
   then writeln('FHTAGN!')
    else writeln('NO');

End.