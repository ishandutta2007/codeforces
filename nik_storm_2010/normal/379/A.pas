var
  a,b,cnt,time:longint;

begin
  readln(a,b);
  time:=0; cnt:=0;
  while (a<>0) do
  begin
    inc(time);
    inc(cnt);
    dec(a);
    if (cnt=b) then begin cnt:=1; inc(time); end;
  end;
  writeln(time);
end.