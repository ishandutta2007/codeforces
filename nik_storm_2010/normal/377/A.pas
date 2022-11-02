var
  a:array[0..1000,0..1000] of char;
  used:array[0..1000,0..1000] of boolean;
  n,m,k,i,j:longint;

procedure dfs(x,y:longint);
begin
  used[x,y]:=true;
  if (a[x-1,y]='.') and (not used[x-1,y]) then dfs(x-1,y);
  if (a[x+1,y]='.') and (not used[x+1,y]) then dfs(x+1,y);
  if (a[x,y-1]='.') and (not used[x,y-1]) then dfs(x,y-1);
  if (a[x,y+1]='.') and (not used[x,y+1]) then dfs(x,y+1);
  if (k<>0) then
  begin
    a[x,y]:='X';
    dec(k);
  end;
end;

begin
  readln(n,m,k);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to n do for j:=1 to m do if (a[i,j]='.') then begin dfs(i,j); break; end;
  for i:=1 to n do
  begin
    for j:=1 to m do write(a[i,j]);
    writeln;
  end;
end.