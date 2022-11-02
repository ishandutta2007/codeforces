var
  n,m,k,ans,kind,i:longint;

begin
  readln(n,m,k);
  ans:=0;
  for i:=1 to n do
  begin
    read(kind);
    if (kind=1) then
    begin
      if (m<>0) then dec(m) else inc(ans);
    end;
    if (kind=2) then
    begin
      if (k<>0) then dec(k) else
      begin
        if (m<>0) then dec(m) else inc(ans);
      end;
    end;
  end;
  writeln(ans);
end.