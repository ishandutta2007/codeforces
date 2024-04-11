var
 a,b:array[0..9,0..9] of char;
  x,y,i,j:longint;
   answer:boolean;
    s:string;



procedure proverka(var rez:boolean);
var i,j,x,y:longint;
 begin
  rez:=true;
   for i:=1 to 8 do
    for j:=1 to 8 do
     if b[i,j]<>'.'
      then
       begin
        if b[i,j]='L'
         then
          begin
           x:=i; y:=j;
            while (b[x,y]<>'#') and (b[x,y]<>'W') do
             begin
              if b[x,y]='B' then exit;
               inc(x);
             end;
           x:=i; y:=j;
            while (b[x,y]<>'#') and (b[x,y]<>'W') do
             begin
              if b[x,y]='B' then exit;
               dec(x);
             end;
           x:=i; y:=j;
            while (b[x,y]<>'#') and (b[x,y]<>'W') do
             begin
              if b[x,y]='B' then exit;
               inc(y);
             end;
           x:=i; y:=j;
            while (b[x,y]<>'#') and (b[x,y]<>'W') do
             begin
              if b[x,y]='B' then exit;
               dec(y);
             end;
          end;
        if b[i,j]='W'
         then
          begin
           if (b[i-1,j-1]='B') or (b[i-1,j]='B') or (b[i-1,j+1]='B') or (b[i,j-1]='B') or (b[i,j+1]='B') or (b[i+1,j-1]='B') or (b[i+1,j]='B') or (b[i+1,j+1]='B')
            then
             begin
              exit;
             end;
          end;
       end;
  rez:=false;
 end;


procedure untilprogram;
var i,j:longint;
 begin
  for i:=1 to 8 do
   for j:=1 to 8 do
  a[i,j]:='.';
  for i:=0 to 9 do
   begin
    a[i,0]:='#';
     a[i,9]:='#';
     a[0,i]:='#';
    a[9,i]:='#';
   end;
 end;


begin

  untilprogram;
   readln(s);
    x:=ord(s[1])-96;
     y:=9-(ord(s[2])-48);
    a[x,y]:='L';
    x:=ord(s[4])-96;
     y:=9-(ord(s[5])-48);
    a[x,y]:='L';
    x:=ord(s[7])-96;
     y:=9-(ord(s[8])-48);
    a[x,y]:='W';
    x:=ord(s[10])-96;
     y:=9-(ord(s[11])-48);
    a[x,y]:='B';
   b:=a;
   proverka(answer);
    if answer = false
     then
      begin
       writeln('OTHER');
        halt;
      end
     else
      begin
       for i:=-1 to 1 do
        for j:=-1 to 1 do
         if not((i=0) and (j=0)) and (x+i>=1) and (x+i<=8) and (y+j>=1) and (y+j<=8)
          then
           begin
            b:=a;
             b[x,y]:='.'; b[x+i,y+j]:='B';
              proverka(answer);
             if answer = false
              then
               begin
                writeln('OTHER');
                 halt;
               end;
           end;
      end;
  writeln('CHECKMATE');

end.