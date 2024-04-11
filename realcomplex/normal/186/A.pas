Var
  a,b:string;
  i,cnt:longint;
  ct:array[1..26] of longint;
Begin
  readln(a);
  readln(b);
  if not(Length(a)=Length(b)) then
  begin
    writeln('NO');
    exit;
  end;
  for i:=1 to 26 do
    ct[i]:=0;
  for i:=1 to Length(a) do
    ct[ord(a[i])-96]+=1;
  for i:=1 to Length(b) do
    ct[ord(b[i])-96]-=1;
  for i:=1 to 26 do
    if not(ct[i]=0) then 
    begin
      writeln('NO');
      exit;
    end;
  cnt:=0;
  for i:=1 to Length(a) do
  begin
    if not(a[i]=b[i]) then
      cnt:=cnt+1;
  end;
  if (cnt=0) or (cnt=2) then
    writeln('YES')
  else
    writeln('NO');
End.