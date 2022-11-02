var
  a,b:array[1..100] of longint;
  n,i,s1,s2:longint;

begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i],b[i]);
    s1:=s1+a[i];
    s2:=s2+b[i];
  end;
  if (s1 mod 2=0) and (s2 mod 2=0) then begin writeln(0); halt; end;
  for i:=1 to n do
  begin
    if ((s1-a[i]+b[i]) mod 2=0) and ((s2-b[i]+a[i]) mod 2=0) then
    begin
      writeln(1);
      halt;
    end;
  end;
  writeln(-1);
end.