program A102;
var
   g : array[1..100,1..100] of integer;
   s : array[1..100] of longint;
   n,m,x,y,i,j,min : longint;


Begin

  readln(n,m);
   for i:=1 to n do read(s[i]);

   for i:=1 to m do
    begin
     readln(x,y);
      g[x,y]:=1;
       g[y,x]:=1;
    end;

  min:=MaxLongint;
   for i:=1  to n do
    for j:=i+1 to n do
     for y:=j+1 to n do
      if (g[i,j]=1) and (g[j,y]=1) and (g[i,y]=1) and (s[i]+s[j]+s[y]<min)
       then
        begin
         min:=s[i]+s[j]+s[y];
        end;

  if min = MaxLongint then writeln(-1)
                      else writeln(min);

End.