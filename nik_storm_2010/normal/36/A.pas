Program A36;
Var
  b : Array[1..100] of LongInt;
  ras,n,i,kol : LongInt;
  s : string;


BEGIN

  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);

  readln(n);
  readln(s);
  kol:=0;

  for i:=1 to n do
   if s[i]='1' then
                   begin
                    inc(kol);
                    b[kol]:=i;
                   end;

   ras:=b[2]-b[1];
   for i:=3 to kol do
    if b[i]-b[i-1]<>ras then
                            begin
                             writeln('NO');
                             close(output);
                             close(input);
                             halt;
                            end;

   writeln('YES');
   close(output);
   close(input);

END.