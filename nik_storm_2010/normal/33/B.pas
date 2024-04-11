Uses
   math;
Var
    g: array[97..122,97..122] of longint;
     leng1,leng2,i,j,y,coast,answer,m,n: longint;
      s1,s2: ansistring;
       c1,space,c2,chosen: char;


Begin

  for i:=97 to 122 do
   for j:=97 to 122 do
    if i<>j then g[i,j]:=1000;

  readln(s1); readln(s2);
   readln(n);
    for i:=1 to n do
     begin
      readln(c1,space,c2,coast);
       g[ord(c1),ord(c2)]:=min(coast , g[ord(c1),ord(c2)]);
     end;

  for y:=97 to 122 do
   for i:=97 to 122 do
    for j:=97 to 122 do
     if g[i,j] > g[i,y] + g[y,j] then g[i,j]:=g[i,y]+g[y,j];

  leng1:=length(s1);
   leng2:=length(s2);
    if leng1<>leng2 then begin writeln(-1); halt; end;

  answer:=0;
   for y:=1 to leng1 do
    if s1[y]<>s2[y]
     then
      begin
       m:=500; chosen:='-';
        for i:=97 to 122 do
         if ( g[ord(s1[y]),i] + g[ord(s2[y]),i] < m )
          then
           begin
            m:=g[ord(s1[y]),i] + g[ord(s2[y]),i];
             chosen:=chr(i);
           end;
       if chosen = '-' then begin writeln(-1); halt; end;
        inc(answer,m);
       s1[y]:=chosen;
      end;
  writeln(answer);
   writeln(s1);

End.