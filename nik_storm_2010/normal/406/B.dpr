const
  l=1000000;
var
  used,now:array[1..l] of boolean;
  n,i,x,pair,ans:longint;

begin
  readln(n);
  for i:=1 to n do
  begin
    read(x);
    used[x]:=true;
  end;
  for i:=1 to l div 2 do
  begin
    if (not used[i]) and (not used[l-i+1]) then continue;
    if (used[i]) and (not used[l-i+1]) then
    begin
      now[l-i+1]:=true;
    end
    else
    if (not used[i]) and (used[l-i+1]) then
    begin
      now[i]:=true;
    end
    else inc(pair);
  end;
  for i:=1 to l div 2 do
  begin
    if (pair=0) then break;
    if (used[i]=false) and (used[l-i+1]=false) then
    begin
      now[i]:=true;
      now[l-i+1]:=true;
      dec(pair);
    end;
  end;
  ans:=0;
  for i:=1 to l do if (now[i]) then inc(ans);
  writeln(ans);
  for i:=1 to l do if (now[i]) then write(i,' ');
end.