var
  a,raz,res,num:array[1..200000] of int64;
  n,i,ans,cnt,j:longint;
  w,d:int64;
  have:boolean;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (a[i]<d) do inc(i);
    while (a[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

procedure add(x:int64);
var
  i:longint;
begin
  for i:=1 to ans do if (res[i]=x) then exit;
  inc(ans);
  res[ans]:=x;
end;

procedure answer;
var
  i,j:longint;
  w:int64;
begin
  for i:=1 to ans do for j:=i+1 to ans do if (res[i]>res[j]) then
  begin
    w:=res[i];
    res[i]:=res[j];
    res[j]:=w;
  end;
  writeln(ans);
  for i:=1 to ans do write(res[i],' ');
  halt;
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  randomize;
  sort(1,n);
  ans:=0;
  if (n=1) then begin writeln(-1); halt; end;
  if (n=2) then
  begin
    d:=a[2]-a[1];
    add(a[1]-d);
    add(a[2]+d);
    if (d mod 2=0) then add(a[1]+d div 2);
    answer;
  end;
  cnt:=0;
  for i:=1 to n-1 do
  begin
    d:=a[i+1]-a[i];
    have:=false;
    for j:=1 to cnt do if (raz[j]=d) then
    begin
      have:=true;
      num[j]:=num[j]+1;
    end;
    if (not have) then
    begin
      inc(cnt);
      if (cnt>2) then begin writeln(0); halt; end;
      raz[cnt]:=d;
      num[cnt]:=1;
    end;
  end;
  if (cnt=1) then
  begin
    add(a[1]-d);
    add(a[n]+d);
    answer;
  end
  else
  begin
    if (raz[1]>raz[2]) then
    begin
      w:=raz[1]; raz[1]:=raz[2]; raz[2]:=w;
      w:=num[1]; num[1]:=num[2]; num[2]:=w;
    end;
    if (raz[1]=0) then begin writeln(0); halt; end;
    if (raz[1]*2<>raz[2]) or (num[2]<>1) then begin writeln(0); halt; end;
    for i:=1 to n-1 do
    begin
      d:=(a[i+1]-a[i]);
      if (d=raz[2]) then begin add(a[i]+raz[1]); answer; end;
    end;
  end;
end.