var
  a,d:array[1..4] of longint;
  cnt,i:longint;

procedure ans(s:string);
begin
  writeln(s);
  halt;
end;

begin
  for i:=1 to 4 do readln(a[i],d[i]);
  if ((a[1]>d[3]) and (d[2]>a[4])) and ((a[1]>d[4]) and (d[2]>a[3])) then ans('Team 1');
  if ((d[1]>a[3]) and (a[2]>d[4])) and ((d[1]>a[4]) and (a[2]>d[3])) then ans('Team 1');
  cnt:=0;
  if ((a[3]>d[1]) and (d[4]>a[2])) or ((a[4]>d[1]) and (d[3]>a[2])) then inc(cnt);
  if ((a[3]>d[2]) and (d[4]>a[1])) or ((a[4]>d[2]) and (d[3]>a[1])) then inc(cnt);
  if (cnt=2) then ans('Team 2') else ans('Draw');
end.