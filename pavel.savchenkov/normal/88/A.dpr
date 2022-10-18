program MINOR;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 i:integer;
 c:char; a,s1,s2,s3,x,y,z:string;
 s:array [1..24] of string=
 ('C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'B', 'H','C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'B', 'H');
function d(c1,c2:string):integer;
var i1,i2,i:integer;
begin
 for i:=1 to 24 do
  if s[i]=c1 then begin i1:=i; break end;
 for i:=i1+1 to 24 do
  if s[i]=c2 then begin d:=i-i1; break end;

end;

begin

 read(a); a:=a+' ';
 for i:=1 to length(a) do
  if a[i]=' ' then begin s1:=copy(a,1,i-1); a:=copy(a,i+1,length(a)-i); break end;

  for i:=1 to length(a) do
  if a[i]=' ' then begin s2:=copy(a,1,i-1); a:=copy(a,i+1,length(a)-i); break end;

   for i:=1 to length(a) do
  if a[i]=' ' then begin s3:=copy(a,1,i-1); a:=copy(a,i+1,length(a)-i); break end;

 
 if (d(s1,s2)=3) and (d(s2,s3)=4) then begin writeln('minor'); halt end
  else if (d(s1,s2)=4) and (d(s2,s3)=3) then begin writeln('major'); halt end;

 x:=s1; y:=s2; z:=s3;
  s2:=z; s3:=y;

  if (d(s1,s2)=3) and (d(s2,s3)=4) then begin writeln('minor'); halt end
  else if (d(s1,s2)=4) and (d(s2,s3)=3) then begin writeln('major'); halt end;

  s1:=z; s2:=x; s3:=y;

   if (d(s1,s2)=3) and (d(s2,s3)=4) then begin writeln('minor'); halt end
  else if (d(s1,s2)=4) and (d(s2,s3)=3) then begin writeln('major'); halt end;

  s1:=z; s2:=y; s3:=x;

   if (d(s1,s2)=3) and (d(s2,s3)=4) then begin writeln('minor'); halt end
  else if (d(s1,s2)=4) and (d(s2,s3)=3) then begin writeln('major'); halt end;

  s1:=y; s2:=x; s3:=z;

   if (d(s1,s2)=3) and (d(s2,s3)=4) then begin writeln('minor'); halt end
  else if (d(s1,s2)=4) and (d(s2,s3)=3) then begin writeln('major'); halt end;

  s2:=z; s3:=x;

   if (d(s1,s2)=3) and (d(s2,s3)=4) then begin writeln('minor'); halt end
  else if (d(s1,s2)=4) and (d(s2,s3)=3) then begin writeln('major'); halt end;

  writeln('strange');



end.