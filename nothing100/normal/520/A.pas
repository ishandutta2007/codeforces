var
  n:longint;
  f:array [1..26] of boolean;
procedure init;
var
  i,o:longint;
  ch:char;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(ch);
    if (ord(ch)>=ord('a')) and (ord(ch)<=ord('z')) then o:=ord(ch)-ord('a')+1
    else o:=ord(ch)-ord('A')+1;
    f[o]:=true;
  end;
  for i:=1 to 26 do
  if not f[i] then
  begin
    writeln('NO');
    exit;
  end;
  writeln('YES');
end;
begin
  init;
end.