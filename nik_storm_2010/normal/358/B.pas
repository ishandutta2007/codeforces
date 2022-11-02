const
  ll=100000+10;
var
  s:array[0..ll] of ansistring;
  d:array[0..ll] of longint;
  n,i,k,j,dd,find,o:longint;
  ss:ansistring;

procedure ans(s:string);
begin
  writeln(s);
  halt;
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s[i]);
    d[i]:=length(s[i]);
  end;
  readln(ss);
  dd:=length(ss);
  j:=1;
  for i:=1 to n do
  begin
    if (j>dd) then ans('no');
    while (j<=dd) and (ss[j]<>'<') do inc(j);
    if (j>dd) then ans('no');
    while (j<=dd) and (ss[j]<>'3') do inc(j);
    if (j>dd) then ans('no');
    o:=1;
    while (j<=dd) and (o<=d[i]) do
    begin
      if (ss[j]=s[i,o]) then inc(o);
      inc(j);
    end;
  end;
  if (j>dd) then ans('no');
  find:=0;
  for i:=j to dd do if (ss[i]='<') then begin inc(find); j:=i+1; break; end;
  for i:=j to dd do if (ss[i]='3') then begin inc(find); break; end;
  if (find=2) then ans('yes') else ans('no');
end.