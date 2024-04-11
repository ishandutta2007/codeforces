Var
    g: array[1..100,1..100] of longint;
     path: array[1..100] of longint;
      used: array[1..100] of boolean;
       i,j,a,b,n,k,max,answer,y: longint;


procedure deikstra(start:longint);
var i,j,nom,min:longint;
 begin
  for i:=1 to n do
   begin
    used[i]:=false;
     path[i]:=MaxLongint;
   end;
  path[start]:=0;
   for i:=1 to n do
    begin
     min:=MaxLongint;
      for j:=1 to n do
       if (min > path[j]) and (used[j]=false)
        then
         begin
          min:=path[j];
           nom:=j;
         end;
     used[nom]:=true;
      for j:=1 to n do
       if (g[nom,j]<>0) and (path[j]>path[nom]+g[nom,j])
        then
         begin
          path[j]:=path[nom]+g[nom,j];
         end;
    end;
 end;


Begin

  answer:=0;
  assign(input,'input.txt');
   reset(input);
    readln(k);
     for i:=1 to k do
      begin
       fillchar(g,sizeof(g),0);
       read(n);
        for j:=1 to n-1 do
         begin
          read(a,b);
           g[a,b]:=1;
            g[b,a]:=1;
         end;
        max:=0;
         for y:=1 to n do
          begin
           deikstra(y);
            for j:=1 to n do
             if (max < path[j]) and (path[j]<>MaxLongint) then max:=path[j];
          end;
       answer:=answer+max;
        readln;
      end;
   close(input);

  assign(output,'output.txt');
   rewrite(output);
    writeln(answer);
  close(output);

End.