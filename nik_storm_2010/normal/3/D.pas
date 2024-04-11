const
  l=100000;
var
  a,b,h1,h2:array[0..l] of longint;
  balance,size,d,i,m,x,y:longint;
  s:ansistring;
  ans:int64;

procedure swap(i,j:longint);
var
  h:longint;
begin
  h:=h1[i]; h1[i]:=h1[j]; h1[j]:=h;
  h:=h2[i]; h2[i]:=h2[j]; h2[j]:=h;
end;

procedure add(x,y:longint);
var
  i:longint;
begin
  inc(size);
  i:=size;
  h1[i]:=x; h2[i]:=y;
  while (i>1) and (h1[i]<h1[i div 2]) do
  begin
    swap(i,i div 2);
    i:=i div 2;
  end;
end;

procedure del(var x,y:longint);
var
  i,nom:longint;
begin
  x:=h1[1]; y:=h2[1];
  swap(1,size);
  dec(size);
  i:=1;
  while (i*2<=size) do
  begin
    nom:=i*2;
    if (i*2+1<=size) and (h1[nom]>h1[i*2+1]) then nom:=i*2+1;
    if (h1[i]>h1[nom]) then
    begin
      swap(i,nom);
      i:=nom;
    end
    else break;
  end;
end;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do if (s[i]='?') then inc(m);
  for i:=1 to m do readln(a[i],b[i]);
  m:=0;
  
  for i:=1 to d do
  begin
    if (s[i]='(') then inc(balance);
    if (s[i]=')') then dec(balance);
    if (s[i]='?') then
    begin
      inc(m);
      s[i]:=')';
      dec(balance);
      ans:=ans+b[m];
      add(a[m]-b[m],i);
    end;
    if (balance<0) then
    begin
      if (size=0) then begin writeln(-1); halt; end;
      del(x,y);
      ans:=ans+x;
      s[y]:='(';
      balance:=balance+2;
    end;
  end;
  
  if (balance<>0) then begin writeln(-1); halt; end;
  writeln(ans);
  writeln(s);
end.