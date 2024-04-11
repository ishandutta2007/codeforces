const
  l=1000;
var
  a:array[1..l,1..l] of byte;
  sum,i,j,n,x,k,q:longint;

begin
  readln(n);
  sum:=0;
  for i:=1 to n do for j:=1 to n do
  begin
    read(a[i,j]);
  end;
  sum:=0;
  for i:=1 to n do sum:=sum+a[i,i];
  readln(q);
  for i:=1 to q do
  begin
    read(k);
    if (k=3) then
    begin
      write(sum mod 2);
    end;
    if (k=1) then
    begin
      read(x);
      if (a[x,x]=1) then dec(sum) else inc(sum);
      a[x,x]:=1-a[x,x];
    end;
    if (k=2) then
    begin
      read(x);
      if (a[x,x]=1) then dec(sum) else inc(sum);
      a[x,x]:=1-a[x,x];
    end;
  end;
end.