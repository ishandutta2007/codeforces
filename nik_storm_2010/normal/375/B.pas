uses
  math;
const
  lim=5010;
var
  a:array[1..lim,1..lim] of char;
  g:array[1..lim,1..lim] of longint;
  ans,sum,n,m,i,j,l,r:longint;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to n do
  begin
    r:=1;
    for l:=1 to m do
    begin
      if (a[i,l]<>'0') then
      begin
        if (l>r) then r:=l;
        while (r<=m) and (a[i,r]='1') do inc(r);
        inc(g[l,r-l]);
      end;
    end;
  end;
  ans:=0;
  for j:=1 to m do
  begin
    sum:=0;
    for l:=m downto 1 do
    begin
      sum:=sum+g[j,l];
      ans:=max(ans,l*sum);
    end;
  end;
  writeln(ans);
end.