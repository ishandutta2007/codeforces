program chis;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s:string; n,i:integer;
begin
 readln(s);

 n:=0;
 for i:=1 to length(s) do
  if (s[i]='4') or (s[i]='7') then n:=n+1;
 str(n,s);
 for i:=1 to length(s) do if (s[i]<>'4') and (s[i]<>'7') then begin writeln('NO'); halt end;
 writeln('YES');

end.