var
s:ansistring;
temp:ansistring;
posit:longint;
temp2:longint;
now:longint;
masih:boolean;
pertama:boolean;

function check(s:ansistring):longint;
begin
  if copy(s,length(s)-3,4)='lios' then
    check:=0
  else if copy(s,length(s)-4,5)='liala' then
    check:=3
  else if copy(s,length(s)-2,3)='etr' then
    check:=1
  else if copy(s,length(S)-3,4)='etra' then
    check:=4
  else if copy(s,length(s)-5,6)='initis' then
    check:=2
  else if copy(s,length(s)-5,6)='inites' then
    check:=5
  else
    check:=6;
end;

begin
masih:=true;
readln(s);
if pos(' ',s)=0 then
  if check(s)<6 then
    writeln('YES')
  else
    writeln('NO')
else
begin

s:=s+' ';
pertama:=true;
while length(s)>0 do
begin
  temp:=copy(s,1,pos(' ',s)-1);
  delete(s,1,pos(' ',s));
  temp2:=check(temp);
 // writeln(temp);
  if pertama then
  begin
    if (temp2<>0) and (temp2<>1) and (temp2<>3) and (temp2<>4) then
      masih:=false;
    pertama:=false;
  end
  else
  begin
  if now=0 then
  begin
    if (temp2<>0) and (temp2<>1) then
      masih:=false;
  end
  else if now=1 then
  begin
    if (temp2<>2) then
      masih:=false
  end
  else if now=2 then
  begin
    if (temp2<>2) then
      masih:=false;
  end
  else if now=3 then
  begin
    if (temp2<>3) and (temp2<>4) then
      masih:=false;
  end
  else if now=4 then
  begin
    if (temp2<>5) then
      masih:=false
  end
  else if now=5 then
  begin
    if (temp2<>5) then
      masih:=false
  end;
  end;
  now:=temp2;
  if not masih then break;
end;
if masih and (now<>0) and (now<>3) then writeln('YES') else writeln('NO');
end;
end.