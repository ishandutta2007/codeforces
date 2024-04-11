var
trump:char;
num1,num2,suit1,suit2:char;
dum:char;

function convert(a:char):integer;
begin
  case a of
  '6':convert:=6;
  '7':convert:=7;
  '8':convert:=8;
  '9':convert:=9;
  'T':convert:=10;
  'J':convert:=11;
  'Q':convert:=12;
  'K':convert:=13;
  'A':convert:=14;
  end;
end;

begin
  readln(trump);
  readln(num1,suit1,dum,num2,suit2);
  if suit1=suit2 then
    if convert(num1)>convert(num2) then
      writeln('YES')
    else
      writeln('NO')
  else
    if suit1=trump then
      writeln('YES')
    else
      writeln('NO');
end.