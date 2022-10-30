var
  need:array[1..200000] of longint;
  n,i,x,k:longint;

procedure ans(s:string);
begin
  writeln(s);
  halt;
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    readln(x,k);
    if (need[k]=x) then
    begin
      inc(need[k]);
      continue;
    end;
    if (x<need[k]) then else ans('NO');
  end;
  ans('YES');
end.