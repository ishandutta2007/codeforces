var
  used:array[1..1000] of longint; n,m,a,b,i,j:longint;


begin

  readln(n,m);
  for i:=1 to m do
  begin
    readln(a,b);
    inc(used[a]); inc(used[b]);
  end;
  for i:=1 to n do if used[i]=0 then
  begin
    writeln(n-1);
    for j:=1 to n do if i<>j then writeln(i,' ',j);
    halt;
  end;

end.