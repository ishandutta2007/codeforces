program storm;
var rez:array[1..250] of longint;
    kol,k,i,n,tek:longint;


procedure inputdata;
begin
 readln(n);
end;

procedure outputdata;
var i:longint;
begin
 for i:=1 to kol-1 do write(rez[i],' ');
end;

begin
 inputdata; kol:=1; k:=0; tek:=1; i:=1;
 while k<>n-1 do
  begin
  inc(k);
  tek:=tek+i; inc(i);
  while tek>n do tek:=tek-n;
  rez[kol]:=tek; inc(kol);
  end;
 outputdata;
end.