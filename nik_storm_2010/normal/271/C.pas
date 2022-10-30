var
    used:array[1..1000000] of longint; n,k,i:longint;


begin

  readln(n,k); if k*3>n then begin writeln(-1); halt; end;
  for i:=1 to k do
    begin
      used[i*2-1]:=i; used[i*2]:=i; used[k*2+i]:=i;
    end;
  for i:=1 to n do
  if used[i]=0 then write(1,' ') else write(used[i],' ');

end.