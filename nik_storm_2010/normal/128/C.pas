const
  md=round(1e9)+7;
  l=1000+10;
var
  f:array[1..l,0..l] of int64;
  sum:array[0..l] of int64;
  n,m,k,i,j,x:longint;
  ans1,ans2,all:int64;

begin
  readln(n,m,k);
  fillchar(f,sizeof(f),0);
  f[n,0]:=1;
  for j:=1 to k do
  begin
    fillchar(sum,sizeof(sum),0);
    for i:=n downto 1 do
    begin
      sum[i]:=sum[i+1]+f[i,j-1];
      if (sum[i]>=md) then sum[i]:=sum[i]-md;
    end;
    all:=0;
    for i:=n downto 1 do
    begin
      f[i,j]:=all;
      all:=all+sum[i+1];
      if (all>=md) then all:=all-md;
    end;
  end;
  ans1:=0;
  for i:=n downto 1 do ans1:=(ans1+f[i,k]) mod md;
  fillchar(f,sizeof(f),0);
  f[m,0]:=1;
  for j:=1 to k do
  begin
    fillchar(sum,sizeof(sum),0);
    for i:=m downto 1 do
    begin
      sum[i]:=sum[i+1]+f[i,j-1];
      if (sum[i]>=md) then sum[i]:=sum[i]-md;
    end;
    all:=0;
    for i:=m downto 1 do
    begin
      f[i,j]:=all;
      all:=all+sum[i+1];
      if (all>=md) then all:=all-md;
    end;
  end;
  ans2:=0;
  for i:=m downto 1 do ans2:=(ans2+f[i,k]) mod md;
  writeln((ans1*ans2) mod md);
end.