uses math;
 var
    player:array[1..1000] of string; score:array[1..1000] of longint;
     n,i,leng,j,tek,x,y:longint; now:string; c:char;
    perx,pery:extended;


begin

  readln(n);
  for i:=1 to n do
    begin
      now:='';
      while true do
        begin
          read(c); if c=' ' then break;
          now:=now+c;
        end;
      readln(tek);

      for j:=1 to leng do
        if now = player[j]
          then
            begin
              score[j]:=max(score[j],tek);
              now:='-1';
              break;
            end;
      if now<>'-1'
        then
          begin
            inc(leng);
            player[leng]:=now;
            score[leng]:=tek;
          end;
    end;

  writeln(leng);
  for i:=1 to leng do
    begin
      write(player[i],' '); x:=0; y:=0;
      for j:=1 to leng do
        begin
          if score[j]<=score[i] then inc(x);
          if score[j] >score[i] then inc(y);
        end;
      perx:=(x/leng)*100; pery:=(y/leng)*100;

      if perx>=99 then writeln('pro') else
        if (perx>=90) and (pery>1) then writeln('hardcore') else
          if (perx>=80) and (pery>10) then writeln('average') else
        if (perx>=50) and (pery>20) then writeln('random') else
      writeln('noob');
    end;

end.