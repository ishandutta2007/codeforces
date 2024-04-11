var
  s:ansistring;
  i,n:longint;
  ans:int64;

procedure solve(x:longint);
var
  i,j:longint;
  k1,k2:int64;
begin
  k1:=0; k2:=0;
  i:=x-1;
  while (i>=1) do
  begin
    if (s[i]='@') or (s[i]='.') then break;
    if (s[i] in ['a'..'z']) then inc(k1);
    dec(i);
  end;
  if (k1=0) then exit;
  j:=x+1;
  while (j<=n) do
  begin
    if (s[j]='@') or (s[j]='_') then exit;
    if (s[j]='.') then break;
    inc(j);
  end;
  if (j=x+1) then exit;
  inc(j);
  while (j<=n) do
  begin
    if(s[j]='@') or (s[j]='_') or (s[j]='.') or (s[j] in ['0'..'9']) then break;
    inc(k2);
    inc(j);
  end;
  ans:=ans+k1*k2;
end;

begin
  readln(s);
  n:=length(s);
  ans:=0;
  for i:=1 to n do
  begin
    if (s[i]<>'@') then continue;
    solve(i);
  end;
  writeln(ans);
end.