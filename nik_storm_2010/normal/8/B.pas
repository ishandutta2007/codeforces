var
    a: array[1..501,1..501] of integer;
    m: array[1..501,1..501] of boolean;
    och: array[1..2,1..10000] of integer;
    d,i,un,uk,j,x,y: longint;
    s: string;



Begin

  readln(s);
   d:=length(s);

   x:=250; y:=250; m[x,y]:=true;
   for i:=1 to d do
    begin

      if s[i] = 'L' then y:=y-1;
      if s[i] = 'R' then y:=y+1;
      if s[i] = 'U' then x:=x-1;
      if s[i] = 'D' then x:=x+1;
      m[x,y]:=true;

    end;

  for un:=1 to 501 do
   for uk:=1 to 501 do
    a[un,uk]:=1000000;

   a[250,250]:=0;
   och[1,1]:=250; och[2,1]:=250; un:=1; uk:=2;
    while un<>uk do
     begin
      i:=och[1,un]; j:=och[2,un];
      inc(un);

      if (m[i,j-1]=true) and (a[i,j]+1<a[i,j-1]) then begin a[i,j-1]:=a[i,j]+1; och[1,uk]:=i; och[2,uk]:=j-1; inc(uk); end;
      if (m[i,j+1]=true) and (a[i,j]+1<a[i,j+1]) then begin a[i,j+1]:=a[i,j]+1; och[1,uk]:=i; och[2,uk]:=j+1; inc(uk); end;
      if (m[i-1,j]=true) and (a[i,j]+1<a[i-1,j]) then begin a[i-1,j]:=a[i,j]+1; och[1,uk]:=i-1; och[2,uk]:=j; inc(uk); end;
      if (m[i+1,j]=true) and (a[i,j]+1<a[i+1,j]) then begin a[i+1,j]:=a[i,j]+1; och[1,uk]:=i+1; och[2,uk]:=j; inc(uk); end;

     end;

  if a[x,y] = d then writeln('OK')
                 else writeln('BUG');

End.