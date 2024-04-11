var
  ans:int64;
  n,q:longint;
  a,b,l,r,que:array [1..100000] of int64;
procedure pre;
var
  head,tail,i:longint;
begin
  que[1]:=1;
  head:=1;
  tail:=1;
  r[1]:=n;
  for i:=2 to n-1 do
  begin
    r[i]:=n;
    while (tail>=head) and (b[que[tail]]<=b[i]) do
    begin
      r[que[tail]]:=i;
      dec(tail);
    end;
    inc(tail);
    que[tail]:=i;
  end;
  que[1]:=n-1;
  head:=1;
  tail:=1;
  l[n-1]:=0;
  for i:=n-2 downto 1 do
  begin
    l[i]:=0;
    while (tail>=head) and (b[que[tail]]<b[i]) do
    begin
      l[que[tail]]:=i;
      dec(tail);
    end;
    inc(tail);
    que[tail]:=i;
  end;
end;
function min(x,y:int64):int64;
begin
  if x<y then exit(x)
  else exit(y);
end;
function max(x,y:int64):int64;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure init;
var
  i,o,p,j:longint;
begin
  read(n,q);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do b[i]:=abs(a[i+1]-a[i]);
  pre;
  for i:=1 to q do
  begin
    read(o,p);
    ans:=0;
    for j:=o to p-1 do
    begin
      ans:=ans+(j-max(l[j],o-1))*(min(p,r[j])-j)*b[j];
    end;
    writeln(ans);
  end;
end;
begin
  init;
end.