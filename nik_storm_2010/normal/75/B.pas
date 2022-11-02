Var
   g: array[1..100,1..100] of longint;
    m: array[1..100] of string;
     sown,stek,s1,s2: string;
      i,j,d,n,kol,nom1,nom2,p: longint;


Begin

  readln(sown);
   readln(n);
    kol:=1;
     m[1]:=sown;
      for i:=1 to n do
       begin
        readln(stek);
         d:=length(stek);
          s2:='';
           for j:=d-7 downto 1 do
            if stek[j]=' ' then break
                            else s2:=stek[j]+s2;
          s1:='';
           for j:=1 to d do
            if stek[j]=' ' then begin p:=j; break; end
                            else s1:=s1+stek[j];
       nom1:=-1; nom2:=-1;
        for j:=1 to kol do
         begin
          if m[j]=s1 then nom1:=j;
           if m[j]=s2 then nom2:=j;
         end;
       if nom1=-1 then begin inc(kol); m[kol]:=s1; nom1:=kol; end;
        if nom2=-1 then begin inc(kol); m[kol]:=s2; nom2:=kol; end;

       if stek[p+1] = 'p' then begin inc(g[nom1,nom2],15); inc(g[nom2,nom1],15); end else
        if stek[p+1] = 'c' then begin inc(g[nom1,nom2],10); inc(g[nom2,nom1],10); end else
         if stek[p+1] = 'l' then begin inc(g[nom1,nom2],5); inc(g[nom2,nom1],5); end;

     end;

  for i:=1 to kol-1 do
   for j:=1 to kol-1 do
    if (g[1,j]>g[1,j+1]) or ((g[1,j]=g[1,j+1]) and (m[j]<m[j+1]))
     then
      begin
       p:=g[1,j]; g[1,j]:=g[1,j+1]; g[1,j+1]:=p;
        stek:=m[j]; m[j]:=m[j+1]; m[j+1]:=stek;
      end;

  for i:=kol downto 1 do
   if m[i] <> sown then writeln(m[i]);

End.