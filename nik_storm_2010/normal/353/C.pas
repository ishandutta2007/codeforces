uses
  math;
var
  a:array[1..200000] of longint;
  f:array[1..200000,-1..1] of longint;
  s:array[1..200000] of char;
  n,i:longint;

begin
  readln(n);
  for i:=1 to n do begin f[i,0]:=-1; f[i,-1]:=-1; f[i,+1]:=-1; end;
  for i:=1 to n do read(a[i]);
  readln;
  for i:=1 to n do read(s[i]);
  if (s[n]='1') then
  begin
    f[n,0]:=a[n];
    f[n,-1]:=0;
  end
  else f[n,0]:=0;
  for i:=n downto 2 do
  begin
    if (f[i,-1]<>-1) then f[i-1,-1]:=max(f[i-1,-1],f[i,-1]+a[i-1]);
    if (f[i,0]<>-1) then
    begin
      if (s[i-1]='1') then
      begin
        f[i-1,0]:=max(f[i-1,0],f[i,0]+a[i-1]);
        f[i-1,-1]:=max(f[i-1,-1],f[i,0]);
      end
      else f[i-1,0]:=max(f[i-1,0],f[i,0]);
    end;
  end;
  writeln(max(f[1,0],f[1,-1]));
end.