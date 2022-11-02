var
  n,k,m,ans,h:longint;
procedure init;
var
  i,j,o,p:longint;
begin
  read(n,k);
  for i:=1 to k do
  begin
    read(o);
    ans:=ans+(o-1);
    for j:=1 to o do
    begin
      read(p);
      if p<>j then break;
      inc(h);
    end;
    readln;
  end;
  ans:=ans+n-1-2*(h-1);
  writeln(ans);
end;
begin
  init;
end.