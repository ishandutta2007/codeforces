var
  ver,gor:array[1..100] of boolean; a:array[1..100,1..100] of char;
  n,i,j:longint; flag:boolean;


begin

  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do read(a[i,j]);
    readln;
  end;
  for i:=1 to n do
    for j:=1 to n do
    if a[i,j]='.' then
    begin
      gor[i]:=true;
      ver[j]:=true;
    end;
  flag:=true;
  for i:=1 to n do flag:=flag and gor[i];
  if flag then
  begin
    for i:=1 to n do
      for j:=1 to n do
      if (a[i,j]='.') and (gor[i]=true) then
      begin
        writeln(i,' ',j);
        gor[i]:=false;
      end;
    halt;
  end;
  flag:=true;
  for i:=1 to n do flag:=flag and ver[i];
  if flag then
  begin
    for i:=1 to n do
      for j:=1 to n do
      if (a[i,j]='.') and (ver[j]=true) then
      begin
        writeln(i,' ',j);
        ver[j]:=false;
      end;
    halt;
  end;
  writeln(-1);

end.