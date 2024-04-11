Uses
    math;
Var
    a: array[1..30,1..30] of char;
     leng: array[97..122] of extended;
      used: array[97..122] of boolean;
       q,i,j,y1,y2,n,m,x,answer,k: longint;
        mi: extended;
         sim: char;



Begin

  readln(n,m,x);
   for i:=1 to n do
    begin
     for j:=1 to m do read(a[i,j]);
      readln;
    end;

  for k:=97 to 122 do
   begin
    sim:=chr(k); leng[k]:=MaxLongint;
     for i:=1 to n do
      for j:=1 to m do
       if a[i,j] = sim
        then
         begin

          mi:=MaxLongint;
           for y1:=1 to n do
            for y2:=1 to m do
             if (a[y1,y2] = 'S') and (sqrt(sqr(y1-i) + sqr(y2-j)) < mi)
              then mi:=sqrt(sqr(y1-i)+sqr(y2-j));
          leng[k]:=min(mi,leng[k]);

         end;
   end;
  for i:=1 to n do
   for j:=1 to m do
    if a[i,j]<>'S' then used[ord(a[i,j])]:=true;

  readln(q); answer:=0;
   for i:=1 to q do
    begin
     read(sim);
      if ord(sim) >= 97
       then
        begin
         if used[ord(sim)] = false then begin writeln(-1); halt; end;
        end
       else
        begin
         if (used[ord(sim)+32] = false) or (leng[ord(sim)+32]=MaxLongint) then begin writeln(-1); halt; end;
          if leng[ord(sim)+32] > x then inc(answer);
        end;
    end;
  writeln(answer);

End.