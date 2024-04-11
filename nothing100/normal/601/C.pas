var
  n,m:longint;
  a:array [1..100] of longint;
  dp:array [0..1,0..100000] of double;
  sum:array [0..100000] of double;
procedure init;
var
  i,la,no,j,ssum:longint;
  num:double;
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  if m=1 then 
  begin
    writeln(1);
    exit;
  end;
  for i:=1 to m do
  if i<>a[1] then dp[1,i]:=1/(m-1);
  for i:=2 to n do
  begin
    la:=(i and 1) xor 1;
    no:=i and 1;
    for j:=1 to n*m do sum[j]:=sum[j-1]+dp[la,j];
    for j:=1 to i*m do
    if (j>a[i]) and (j>m) then dp[no,j]:=(sum[j-1]-sum[j-m-1]-dp[la,j-a[i]])/(m-1)
    else if (j>a[i]) then dp[no,j]:=(sum[j-1]-dp[la,j-a[i]])/(m-1)
    else dp[no,j]:=sum[j-1]/(m-1);
  end;
  ssum:=0;
  num:=0;
  for j:=1 to n do ssum:=ssum+a[j];
  for j:=1 to ssum-1 do num:=num+dp[no,j];
  writeln(num*(m-1)+1:0:13);
end;
begin
  init;
end.