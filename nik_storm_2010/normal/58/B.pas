program storm;
var m:array[1..10000] of longint;
    n,kol,i,delit:longint;


procedure inputdata;
begin
 readln(n);
end;

procedure outputdata;
begin
 for i:=1 to (kol-1) do write(m[i],' ');
end;

procedure del(chiclo:longint; var delit:longint);
var i:longint;
begin
 for i:=2 to round(sqrt(chiclo)) do
  if chiclo mod i = 0 then begin delit:=i; exit; end;
 delit:=chiclo;
end;

begin
 inputdata; kol:=1;
 m[1]:=n; inc(kol);
 while n<>1 do
  begin
  del(n,delit);
  m[kol]:=n div delit; inc(kol);
  n:=n div delit;
  end;
 outputdata;
end.