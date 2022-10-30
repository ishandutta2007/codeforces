var
  used:array['a'..'z'] of boolean;
  m:array[1..200000] of ansistring;
  res:ansistring;
  cnt,d,i,j,n:longint;
  c,x:char;

begin
  readln(n);
  for i:=1 to n do readln(m[i]);
  d:=length(m[1]);
  for i:=1 to d do res:=res+'?';
  for i:=1 to d do
  begin
    fillchar(used,sizeof(used),false);
    for j:=1 to n do if (m[j,i]<>'?') then used[m[j,i]]:=true;
    cnt:=0;
    c:='?';
    for x:='a' to 'z' do if (used[x]) then begin inc(cnt); c:=x; end;
    if (cnt=0) then res[i]:='a';
    if (cnt=1) then res[i]:=c;
  end;
  writeln(res);
end.