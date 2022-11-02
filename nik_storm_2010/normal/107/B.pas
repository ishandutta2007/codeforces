const
  l=1000;
var
  s:array[1..l] of longint;
  ans:extended;
  n,m,h,sum,i:longint;

begin
  readln(n,m,h);
  for i:=1 to m do read(s[i]);
  sum:=0;
  for i:=1 to m do sum:=sum+s[i];
  if (sum<n) then begin writeln(-1); halt; end;
  dec(s[h]);
  dec(n);
  dec(sum);
  if (sum-s[h]<n) then begin writeln(1); halt; end;
  ans:=1;
  for i:=0 to n-1 do ans:=ans*(sum-i-s[h])/(sum-i);
  writeln((1-ans):0:8);
end.