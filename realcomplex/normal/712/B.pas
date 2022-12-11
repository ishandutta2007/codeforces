var
  a:string;
  i,c1,c2:longint;
begin
  readln(a);
  if Length(a) mod 2 = 1 then
  begin
    writeln('-1');
    exit;
  end;
  c1:=0;
  c2:=0;
  for i:=1 to Length(a) do
  begin
    if a[i]='L' then
      c1-=1;
    if a[i]='R' then
      c1+=1;
    if a[i]='U' then
      c2+=1;
    if a[i]='D' then
      c2-=1;
  end;
  if c1<0 then 
    c1*=-1;
  if c2<0 then
    c2*=-1;
  writeln((c1+c2) div 2);
end.