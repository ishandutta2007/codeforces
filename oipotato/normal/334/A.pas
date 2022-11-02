var i,n:longint;
begin
  readln(n);
  for i:=1 to sqr(n) div 2 do
  begin
    write(i,' ',sqr(n)-i+1,' ');
	if i*2 mod n=0 then writeln;
  end;
end.