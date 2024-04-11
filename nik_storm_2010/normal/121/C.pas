uses
  math;
var
  a,fact:array[0..13] of int64;
  ans,n,k:int64;
  i:longint;

function check(x:int64):boolean;
var
  z:int64;
begin
  check:=false;
  if (x>n) then exit;
  z:=n-x+1;
  if (z<=13) then z:=a[z] else z:=x;
  while (z<>0) do
  begin
    if (z mod 10<>4) and (z mod 10<>7) then exit;
    z:=z div 10;
  end;
  check:=true;
end;

procedure swap(i,j:longint);
var
  x:int64;
begin
  x:=a[i]; a[i]:=a[j]; a[j]:=x;
end;

procedure rec(nom,ost:int64);
var
  x:int64;
  i,j:longint;
  good:boolean;
begin
  if (nom=0) then exit;
  good:=false;
  for i:=nom downto 1 do
  begin
    x:=(nom-i+1)*fact[nom-1];
    if (ost<=x) then begin swap(nom,i); good:=true; break; end;
  end;
  if (not good) then begin writeln('-1'); halt; end;
  for i:=1 to nom-1 do for j:=i+1 to nom-1 do if (a[i]<a[j]) then swap(i,j);
  rec(nom-1,ost-x+fact[nom-1])
end;

procedure gen(nom,x:int64);
begin
  if (nom<>1) and (check(x)) then inc(ans);
  if (nom=10) then exit;
  gen(nom+1,x*10+4);
  gen(nom+1,x*10+7);
end;

begin
  readln(n,k);
  fact[0]:=1;
  for i:=1 to 13 do fact[i]:=fact[i-1]*i;
  for i:=min(13,n) downto 1 do a[i]:=n-i+1;
  rec(min(13,n),k);
  gen(1,0);
  writeln(ans);
end.