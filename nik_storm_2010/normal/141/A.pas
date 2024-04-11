{ Author : Sazanovich Nikita }
{ Memory : 0.001 megabyte }
{ Time : leng1 + leng2 + leng3 + 26 }
var
 a : array[65..90] of longint;
  s1,s2,s3 : string;
   leng,i : longint;



begin

  readln(s1);
   leng:=length(s1);
    for i:=1 to leng do inc(a[ord(s1[i])]);
  readln(s2);
  leng:=length(s2);
   for i:=1 to leng do inc(a[ord(s2[i])]);
  readln(s3);
   leng:=length(s3);
    for i:=1 to leng do dec(a[ord(s3[i])]);

  for i:=65 to 90 do
   if a[i]<>0
    then
     begin
      writeln('NO');
       halt;
     end;
  writeln('YES');

end.