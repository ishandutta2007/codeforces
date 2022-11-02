var
  n,i,x:longint;


begin
  readln(n);
  if (n=3) then begin writeln(5); halt; end;
  for i:=1 to 100 do
  begin
    if (i mod 2=0) then continue;
    x:=(i*i) div 2+1;
    if (n<=x) then
    begin
      writeln(i);
      halt;
    end;
  end;
end.