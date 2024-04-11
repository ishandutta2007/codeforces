const mo=1000000007;
var
  ans:int64;
  n,ma,tot:longint;
  a:array [1..4] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure init;
var
  i:longint;
  ch:char;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(ch);
    if ch='A' then inc(a[1])
    else if ch='C' then inc(a[2])
    else if ch='T' then inc(a[3])
    else inc(a[4]);
  end;
  for i:=1 to 4 do ma:=max(ma,a[i]);
  for i:=1 to 4 do if a[i]=ma then inc(tot);
  ans:=1;
  for i:=1 to n do ans:=(ans*tot) mod mo;
  writeln(ans);
end;
begin
  init;
end.