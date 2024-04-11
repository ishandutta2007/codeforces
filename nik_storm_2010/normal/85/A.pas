Program A85;
Var
  a : Array[1..4,1..100] of Char;
  n,i,j,c,c1 : LongInt;


BEGIN

  readln(n);

  if n=1 then
             begin
               writeln('a');
               writeln('a');
               writeln('b');
               writeln('b');
               halt;
             end;
  if n=2 then
             begin
               writeln('aa');
               writeln('bb');
               writeln('cc');
               writeln('dd');
               halt;
             end;
  if n=3 then
             begin
               writeln('aab');
               writeln('ccb');
               writeln('dee');
               writeln('dff');
               halt;
             end;

  if n mod 2 = 0 then
  begin
    c:=97;
    for i:=1 to (n div 2) do
                            begin
                              a[1,i*2-1]:=chr(c);
                              a[1,i*2]:=chr(c);
                              a[4,i*2-1]:=chr(c);
                              a[4,i*2]:=chr(c);
                              If c=97 then c:=98
                                      else c:=97;
                             end;
    c:=99; c1:=101;
    for i:=1 to (n div 2)-1 do
                              begin
                                a[2,i*2]:=chr(c);
                                a[2,i*2+1]:=chr(c);
                                a[3,i*2]:=chr(c1);
                                a[3,i*2+1]:=chr(c1);
                                if c=99   then c:=100  else c:=99;
                                if c1=101 then c1:=102 else c1:=101;
                              end;
    a[2,1]:='y'; a[2,n]:='q';
    a[3,1]:='y'; a[3,n]:='q';
  end
             else
  begin
    c:=97; c1:=99;
    for i:=1 to n div 2 do
                          begin
                          a[1,i*2-1]:=chr(c);  a[1,i*2]:=chr(c);
                          a[2,i*2-1]:=chr(c1); a[2,i*2]:=chr(c1);
                          a[3,i*2]:=chr(c);    a[3,i*2+1]:=chr(c);
                          a[4,i*2]:=chr(c1); a[4,i*2+1]:=chr(c1);
                          if c1=99 then c1:=100 else c1:=99;
                          if c=97  then c:=98   else c:=97;
                          end;
    a[1,n]:='y'; a[2,n]:='y';
    a[3,1]:='q'; a[4,1]:='q';
  end;


  for i:=1 to 4 do
   begin

     for j:=1 to n do write(a[i,j]);
     writeln;

   end;

END.