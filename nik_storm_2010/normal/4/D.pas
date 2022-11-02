Var
   sizes: array[1..3,0..5000] of longint;
    dinamic: array[1..4,0..5000] of longint;
     tmp,n,i,a,b,kol,j,nom: longint;


procedure qsort(l,r:longint);
var i,j,dw,dh,tmp:longint;
 begin
  i:=l; j:=r;
   dw:=sizes[1,(i+j) div 2]; dh:=sizes[2,(i+j) div 2];
    while i<=j do
     begin

      while (sizes[1,i]<dw) or ((sizes[1,i]=dw) and (sizes[2,i]<dh)) do inc(i);
      while (sizes[1,j]>dw) or ((sizes[1,j]=dw) and (sizes[2,j]>dh)) do dec(j);
       if i<=j
        then
         begin
          tmp:=sizes[1,i]; sizes[1,i]:=sizes[1,j]; sizes[1,j]:=tmp;
           tmp:=sizes[2,i]; sizes[2,i]:=sizes[2,j]; sizes[2,j]:=tmp;
            tmp:=sizes[3,i]; sizes[3,i]:=sizes[3,j]; sizes[3,j]:=tmp;
             inc(i); dec(j);
         end;

     end;
   if i<r then qsort(i,r);
  if l<j then qsort(l,j);
 end;


Begin

  readln(n,sizes[1,0],sizes[2,0]); sizes[3,0]:=0;
   for i:=1 to n do
    begin
     readln(sizes[1,i],sizes[2,i]);
      sizes[3,i]:=i
    end;

  qsort(0,n);
   for i:=n downto 0 do
    begin

     dinamic[1,i]:=sizes[1,i]; dinamic[2,i]:=sizes[2,i]; dinamic[3,i]:=i; dinamic[4,i]:=1;
      for j:=i+1 to n do
       if (dinamic[1,i]<dinamic[1,j]) and (dinamic[2,i]<dinamic[2,j]) and (dinamic[4,i]<dinamic[4,j]+1)
        then
         begin
          dinamic[3,i]:=j;
           dinamic[4,i]:=dinamic[4,j]+1;
         end;

    end;

  for i:=0 to n do if sizes[3,i]=0 then begin nom:=i; break; end;
   writeln(dinamic[4,nom]-1);
    while dinamic[3,nom]<>nom do
     begin
      nom:=dinamic[3,nom];
       write(sizes[3,nom],' ');
     end;

End.