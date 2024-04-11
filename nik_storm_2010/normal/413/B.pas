const
  ln=20000+10;
  lm=10+10;
var
  g,was:array[1..ln,1..lm] of longint;
  cnt:array[1..lm] of longint;
  sum,n,m,k,i,j,x,y:longint;

begin
  readln(n,m,k);
  for i:=1 to n do for j:=1 to m do
  begin
    read(g[i,j]);
    if (j=m) then readln;
  end;
  for i:=1 to k do
  begin
    readln(x,y);
    inc(was[x,y]);
    inc(cnt[y]);
  end;
  for i:=1 to n do
  begin
    sum:=0;
    for j:=1 to m do if (g[i,j]=1) then sum:=sum+cnt[j]-was[i,j];
    write(sum);
    if (i<>n) then write(' ');
  end;
end.