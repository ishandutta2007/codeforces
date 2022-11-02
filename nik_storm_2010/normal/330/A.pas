var
  u:array[1..10,1..10] of boolean; ver,gor:array[1..10] of boolean;
  r,c,i,j,ans:longint; sim:char;


begin

  readln(r,c);
  for i:=1 to r do
  begin
    for j:=1 to c do
    begin
      read(sim);
      if (sim='S') then
      begin
        gor[i]:=true; ver[j]:=true;
      end;
    end;
    readln;
  end;
  ans:=0;
  for i:=1 to r do if not gor[i] then
  begin
    for j:=1 to c do if u[i,j]=false then
    begin
      inc(ans); u[i,j]:=true;
    end;
  end;
  for i:=1 to c do if not ver[i] then
  begin
    for j:=1 to r do if u[j,i]=false then
    begin
      inc(ans); u[j,i]:=true;
    end;
  end;
  writeln(ans);

end.