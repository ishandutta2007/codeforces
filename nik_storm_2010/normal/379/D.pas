var
  f:array[1..50] of int64;
  a,b:array[1..50] of boolean;
  k,x,n,m:int64;
  i,j:longint;

procedure answer;
var
  i:longint;
begin
  if (n=1) then
  begin
    if (a[1]) then write('C') else
    begin
      if (b[1]) then write('A') else write('Z');
    end;
  end
  else
  begin
    if (a[1]) then begin write('C'); dec(n); end;
    for i:=1 to f[1] do begin write('AC'); n:=n-2; end;
    while (n>1) do begin write('Z'); dec(n); end;
    if (n=1) then
    begin
      if (b[1]) then write('A') else write('Z');
    end;
  end;
  writeln;
  if (m=1) then
  begin
    if (a[2]) then write('C') else
    begin
      if (b[2]) then write('A') else write('Z');
    end;
  end
  else
  begin
    if (a[2]) then begin write('C'); dec(m); end;
    for i:=1 to f[2] do begin write('AC'); m:=m-2; end;
    while (m>1) do begin write('Z'); dec(m); end;
    if (m=1) then
    begin
      if (b[2]) then write('A') else write('Z');
    end;
  end;
  halt;
end;

procedure check;
var
  i:longint;
begin
  for i:=3 to k do
  begin
    f[i]:=f[i-1]+f[i-2];
    if (b[i-2]) and (a[i-1]) then f[i]:=f[i]+1;
    if (f[i]>x) then exit;
    a[i]:=a[i-2];
    b[i]:=b[i-1];
  end;
  if (f[k]=x) then answer;
end;

procedure find2;
var
  i:longint;
begin
  if (m=1) then
  begin
    f[2]:=0;
    a[2]:=true;
    b[2]:=false;
    check;
    a[2]:=false;
    b[2]:=true;
    check;
    a[2]:=false;
    b[2]:=false;
    check;
    exit;
  end;
  for i:=0 to (m div 2) do
  begin
    f[2]:=i;
    a[2]:=false;
    b[2]:=false;
    check;
    if (i*2+2<=m) then
    begin
      a[2]:=true;
      b[2]:=true;
      check;
    end;
    if (i*2+1<=m) then
    begin
      a[2]:=true;
      b[2]:=false;
      check;
      a[2]:=false;
      b[2]:=true;
      check;
    end;
  end;
end;

procedure find1;
var
  i:longint;
begin
  if (n=1) then
  begin
    f[1]:=0;
    a[1]:=true;
    b[1]:=false;
    find2;
    a[1]:=false;
    b[1]:=true;
    find2;
    a[1]:=false;
    b[1]:=false;
    find2;
    exit;
  end;
  for i:=0 to (n div 2) do
  begin
    f[1]:=i;
    a[1]:=false;
    b[1]:=false;
    find2;
    if (i*2+2<=n) then
    begin
      a[1]:=true;
      b[1]:=true;
      find2;
    end;
    if (i*2+1<=n) then
    begin
      a[1]:=true;
      b[1]:=false;
      find2;
      a[1]:=false;
      b[1]:=true;
      find2;
    end;
  end;
end;

begin
  readln(k,x,n,m);
  find1;
  find2;
  writeln('Happy new year!');
end.