var
  used:array[1..2000] of boolean;
  n,k:longint;
  s:ansistring;

procedure print(x:longint);
begin
  writeln('PRINT ',s[x]);
end;

procedure move(x,dx:longint);
begin
  if (not used[x]) then print(x);
  used[x]:=true;
  while (true) do
  begin
    x:=x+dx;
    if (1<=x) and (x<=n) then else break;
    if (dx=1) then writeln('RIGHT') else writeln('LEFT');
    if (not used[x]) then print(x);
    used[x]:=true;
  end;
end;

begin
  readln(n,k);
  readln(s);
  if (k-1<=n-k) then
  begin
    move(k,-1);
    move(1,+1);
  end
  else
  begin
    move(k,+1);
    move(n,-1);
  end;
end.