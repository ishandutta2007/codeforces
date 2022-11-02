var
    a:array[1..30,1..30] of string[10]; n,m,k,nom,i,j,x,y:longint;
     c:char; tek:string[10]; zn:string[2];


begin

   assign(input,'input.txt'); reset(input);
   readln(n,m,k);

   assign(output,'output.txt'); rewrite(output);
   for nom:=1 to k do
     begin
       read(zn);
       if zn='+1' then
         begin
           read(x,y); read(c); readln(tek); i:=x; j:=y;
           while a[i,j]<>'' do
             begin
               inc(j); if j>m then
                 begin
                   inc(i); j:=1;
                   if i>n then begin i:=-1; j:=-1; break; end;
                 end;
             end;
           if (i<>-1) then
             begin
               a[i,j]:=tek;
             end;
         end
           else
         begin
           read(c); readln(tek); x:=-1; y:=-1;
           for i:=1 to n do
             for j:=1 to m do
               if a[i,j]=tek then
               begin
                 x:=i; y:=j;
                 break;
               end;
           if (x<>-1) then a[x,y]:='';
           writeln(x,' ',y);
         end;
     end;
   close(input); close(output);

end.