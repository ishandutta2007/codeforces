var
  n,m,i,j:longint;
  cor:array[1..100] of longint;
  len:array[1..100] of longint;
  can:array[0..100] of longint;
begin
  for i:=0 to m do
    can[i]:=0;
  readln(n,m);
  for i:=1 to n do
    readln(cor[i],len[i]);
  can[0]:=1;
  for i:=1 to n do
  begin
    if can[cor[i]]=1 then
    for j:=cor[i] to len[i] do
      can[j]:=1;
  end;
  if can[m]=1 then
    writeln('YES')
  else
    writeln('NO');
end.