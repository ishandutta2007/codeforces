var
  sk,v,k,c,cnt:longint;
begin
  readln(sk,k);
  c:=0;
  cnt:=0;
  v:=0;
  if sk=0 then v:=1;
  while sk>0 do
  begin
    if c=k then
    begin
      writeln(cnt); 
      exit;
    end;
    if (sk mod 10) = 0 then
      c+=1
    else
      cnt+=1;
    sk := (sk div 10);
    v+=1;
  end;
  writeln(v-1);
end.