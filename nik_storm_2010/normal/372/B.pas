const
  l=50;
var
  f:array[0..l,0..l,0..l,0..l] of longint;
  a,sum:array[0..l,0..l] of longint;
  n,m,q,i,j,x1,y1,x2,y2,res:longint;
  c:char;

function count(x1,y1,x2,y2:longint):longint; begin exit(sum[x2,y2]-sum[x1-1,y2]-sum[x2,y1-1]+sum[x1-1,y1-1]); end;

begin
  readln(n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(c);
      if (c='0') then a[i,j]:=0 else a[i,j]:=1;
    end;
    readln;
  end;
  for i:=1 to n do for j:=1 to m do sum[i,j]:=sum[i-1,j]+sum[i,j-1]-sum[i-1,j-1]+a[i,j];
  for x1:=1 to n do for y1:=1 to m do for x2:=x1 to n do for y2:=y1 to m do
  begin
    res:=f[x1,y1,x2-1,y2]+f[x1,y1,x2,y2-1]-f[x1,y1,x2-1,y2-1];
    i:=x1;
    for j:=y2 downto y1 do
    begin
      while (i<=x2) and (count(i,j,x2,y2)<>0) do inc(i);
      res:=res+x2-i+1;
    end;
    f[x1,y1,x2,y2]:=res;
  end;
  for i:=1 to q do
  begin
    readln(x1,y1,x2,y2);
    writeln(f[x1,y1,x2,y2]);
  end;
end.