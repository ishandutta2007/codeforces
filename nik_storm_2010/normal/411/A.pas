var
  s:ansistring;
  d,i:longint;
  have:boolean;

procedure bad;
begin
  writeln('Too weak');
  halt;
end;

begin
  readln(s);
  d:=length(s);
  if (d<5) then bad;
  have:=false;
  for i:=1 to d do if (s[i] in ['A'..'Z']) then have:=true;
  if (not have) then bad;
  have:=false;
  for i:=1 to d do if (s[i] in ['a'..'z']) then have:=true;
  if (not have) then bad;
  have:=false;
  for i:=1 to d do if (s[i] in ['0'..'9']) then have:=true;
  if (not have) then bad;
  writeln('Correct');
end.