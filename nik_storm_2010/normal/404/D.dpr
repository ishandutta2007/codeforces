const
  l=1000000+10;
  md=1000000000+7;
var
  a:array[1..l] of integer;
  f:array[1..l,-1..3] of longint;
  d,ans,i:longint;
  s:ansistring;

procedure print(x:longint);
begin
  writeln(x);
  halt;
end;

procedure solve;
var
  i,res,j:longint;
begin
  for i:=2 to d do
  begin
    fillchar(f[i],sizeof(f[i]),0);
    j:=i-1;
    if (a[i]=0) then
    begin
      f[i,0]:=f[j,0]+f[j,1];
    end
    else
    if (a[i]=1) then
    begin
      f[i,1]:=f[j,3];
      f[i,-1]:=f[j,0]+f[j,1];
    end
    else
    if (a[i]=2) then
    begin
      f[i,2]:=f[j,3];
    end
    else
    if (a[i]=3) then
    begin
      f[i,3]:=f[j,-1]+f[j,2];
      if (f[i,3]>=md) then f[i,3]:=f[i,3]-md;
      f[i,3]:=f[i,3]+f[j,3];
    end
    else
    if (a[i]=4) then
    begin
      f[i,0]:=f[j,0]+f[j,1];
      f[i,1]:=f[j,3];
      f[i,-1]:=f[j,0]+f[j,1];
      f[i,2]:=f[j,3];
      f[i,3]:=f[j,-1]+f[j,2];
      if (f[i,3]>=md) then f[i,3]:=f[i,3]-md;
      f[i,3]:=f[i,3]+f[j,3];
    end;
    for j:=-1 to 3 do if (f[i,j]>=md) then f[i,j]:=f[i,j]-md;
  end;
  ans:=ans+f[d,0];
  if (ans>=md) then ans:=ans-md;
  ans:=ans+f[d,1];
  if (ans>=md) then ans:=ans-md;
  ans:=ans+f[d,3];
  if (ans>=md) then ans:=ans-md;
end;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do
  begin
    if (s[i]='1') then a[i]:=1;
    if (s[i]='0') then a[i]:=0;
    if (s[i]='2') then a[i]:=2;
    if (s[i]='*') then a[i]:=3;
    if (s[i]='?') then a[i]:=4;
  end;
  ans:=0;
  if (a[1]=4) then
  begin
    fillchar(f[1],sizeof(f[1]),0);
    f[1,0]:=1;
    solve();
    fillchar(f[1],sizeof(f[1]),0);
    f[1,-1]:=1;
    solve();
    fillchar(f[1],sizeof(f[1]),0);
    f[1,3]:=1;
    solve();
  end
  else
  begin
    fillchar(f[1],sizeof(f[1]),0);
    if (a[1]=2) then print(0);
    if (a[1]=1) then f[1,-1]:=1 else f[1,a[1]]:=1;
    solve();
  end;
  writeln(ans);
end.