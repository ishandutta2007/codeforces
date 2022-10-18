program Pasha;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s:string; n,i:integer;
begin
read(n);
repeat
 s:=s+'GBIV';
until length(s)>=n;
if length(s)>n then delete(s,n+1,length(s)-n);
s[n]:='R';s[n-1]:='O'; s[n-2]:='Y';
writeln(s);
end.