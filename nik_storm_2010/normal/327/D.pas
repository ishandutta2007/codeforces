var
  a:array[0..501,0..501] of char; q:array[1..2,1..1000000] of longint;
  cnt:array[1..3,1..1000000] of longint; ans,st,fn,n,m,i,j:longint;


procedure add(i,j:longint);
begin
  q[1,fn]:=i; q[2,fn]:=j; inc(fn);
end;


procedure out(var i,j:longint);
begin
  i:=q[1,st]; j:=q[2,st]; inc(st);
end;


procedure solve(i,j:longint);
var x,y:longint;
begin
  st:=1; fn:=1; add(i,j); a[i,j]:='R';
  while (st<>fn) do
  begin
    out(x,y);
    if (a[x-1,y]='B') then begin add(x-1,y); a[x-1,y]:='R'; end;
    if (a[x+1,y]='B') then begin add(x+1,y); a[x+1,y]:='R'; end;
    if (a[x,y-1]='B') then begin add(x,y-1); a[x,y-1]:='R'; end;
    if (a[x,y+1]='B') then begin add(x,y+1); a[x,y+1]:='R'; end;
  end;
  for i:=fn-1 downto 2 do
  begin
    inc(ans);
    cnt[1,ans]:=3; cnt[2,ans]:=q[1,i]; cnt[3,ans]:=q[2,i];
    inc(ans);
    cnt[1,ans]:=2; cnt[2,ans]:=q[1,i]; cnt[3,ans]:=q[2,i];
  end;
end;


begin

  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
    if a[i,j]<>'#' then
    begin
      a[i,j]:='B';
      inc(ans);
      cnt[1,ans]:=1; cnt[2,ans]:=i; cnt[3,ans]:=j;
    end;
  for i:=1 to n do
    for j:=1 to m do
    if a[i,j]='B' then
    begin
      solve(i,j);
    end;
  writeln(ans);
  for i:=1 to ans do
  begin
    if cnt[1,i]=1 then write('B ');
    if cnt[1,i]=2 then write('R ');
    if cnt[1,i]=3 then write('D ');
    writeln(cnt[2,i],' ',cnt[3,i]);
  end;

end.