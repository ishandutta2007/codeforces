var
  num,cnt,i,x:longint;


function prime(x:longint):boolean;
var i:longint;
begin
  i:=2;
  while (i*i<=x) do
  begin
    if (x mod i=0) then exit(false);
    inc(i);
  end;
  prime:=true;
end;


function reverse(x:longint):longint;
var res:longint;
begin
  res:=0;
  while (x<>0) do
  begin
    res:=res*10+x mod 10;
    x:=x div 10;
  end;
  reverse:=res;
end;


begin
  readln(num);
  for i:=2 to 1000000 do
  begin
    if (not prime(i)) then continue;
    x:=reverse(i);
    if (i<>x) and (prime(x)) then
    begin
      inc(cnt);
      if (cnt=num) then begin writeln(i); halt; end;
    end;
  end;
end.