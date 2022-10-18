program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s1,s2:string;       i:integer;
begin
 readln(s1);
 readln(s2);
 for i:=1 to length(s1) do
  if ord(s1[i])<97 then s1[i]:=chr(ord(s1[i])+32);
 for i:=1 to length(s2) do
  if ord(s2[i])<97 then s2[i]:=chr(ord(s2[i])+32);
 for i:=1 to length(s1) do
  if (s1[i]<s2[i]) then begin writeln('-1'); halt end else
   if (s1[i]>s2[i]) then begin writeln('1'); halt end;
  writeln('0');
end.