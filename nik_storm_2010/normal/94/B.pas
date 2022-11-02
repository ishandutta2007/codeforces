program B94;
var
  g:array[1..5,1..5] of longint;
  i,j,k,m:longint;
  answer:string;


Begin

  readln(m);
   for i:=1 to m do
    begin
     readln(j,k);
      g[j,k]:=1;
       g[k,j]:=1;
    end;

  answer:='FAIL';
   for i:=1 to 5 do
    for j:=i+1 to 5 do
     for k:=j+1 to 5 do
      if ((g[i,j]=1) and (g[i,k]=1) and (g[j,k]=1)) or
       ((g[i,j]=0) and (g[i,k]=0) and (g[j,k]=0))
        then
         begin

           answer:='WIN';

         end;
  writeln(answer);

End.