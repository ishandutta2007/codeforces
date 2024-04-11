Var
    a: array[0..100,0..100] of char;
     can,pred,next: array[0..9,0..9] of longint;
      i,j,n: longint;
       live: boolean;


function cango(i,j:longint) : boolean;
 begin

   if (pred[i-1,j-1]=1) or (pred[i-1,j]=1) or (pred[i-1,j+1]=1) or (pred[i,j]=1) or (pred[i,j-1]=1) or (pred[i,j+1]=1)
    or (pred[i+1,j-1]=1) or (pred[i+1,j]=1) or (pred[i+1,j+1]=1) then exit(true);
   exit(false);

 end;



Begin

  for i:=1 to 8 do
   begin
    for j:=1 to 8 do read(a[i,j]);
     readln;
   end;

  can[8,1]:=1;
  while can[1,8] <> 1 do
   begin

     for i:=1 to 8 do
      for j:=1 to 8 do
       if (a[i,j]='S') or (a[i-1,j]='S')
        then
         begin
          next[i,j]:=0;
         end
        else
         begin
          next[i,j]:=1;
         end;

     pred:=can; live:=false;
      fillchar(can,sizeof(can),0);
       for i:=1 to 8 do
        for j:=1 to 8 do
         if (next[i,j]=1) and (cango(i,j)=true)
          then
           begin
            can[i,j]:=1;
             live:=true;
           end;
     if live=false then begin writeln('LOSE'); halt; end;
      for i:=8 downto 1 do
       for j:=8 downto 1 do
        if a[i,j]='S'
         then
          begin
           a[i,j]:='.';
            a[i+1,j]:='S';
          end;

   end;
  writeln('WIN');

End.