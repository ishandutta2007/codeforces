var
  f : array[0..30,1..30] of int64;
   n,m,k,i,j : longint;
    answer,boy,girl : int64;




begin

  readln(n,m,k);

   for i:=1 to 30 do f[0,i]:=1; f[1,1]:=1;
    for j:=2 to 30 do
     for i:=1 to 30 do
      f[i,j]:=f[i,j-1]+f[i-1,j-1];

   answer:=0;
    for i:=4 to n do
     for j:=1 to m do
      if i+j=k
       then
        begin

          answer:=answer+(f[i,n]*f[j,m]);

        end;
  writeln(answer);

end.