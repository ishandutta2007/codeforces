{$M 256000000}
uses
  math;
const
  lim=10000000;
var
  cnt,sum,lp,prime:array[0..lim+10] of longint;
  n,x,i,j,size,m,l,r:longint;

procedure factor;
var
  i,j:longint;
begin
  for i:=2 to lim do
  begin
    if (lp[i]=0) then
    begin
      inc(size);
      prime[size]:=i;
      lp[i]:=i;
    end;
    j:=1;
    while (j<=size) and (prime[j]<=lp[i]) and (i*prime[j]<=lim) do
    begin
      lp[i*prime[j]]:=prime[j];
      inc(j);
    end;
  end;
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    read(x);
    inc(cnt[x]);
  end;
  factor;
  for i:=1 to size do
  begin
    x:=prime[i];
    j:=x;
    while (j<=lim) do
    begin
      sum[x]:=sum[x]+cnt[j];
      j:=j+x;
    end;
  end;
  for i:=1 to lim do sum[i]:=sum[i-1]+sum[i];
  readln;
  readln(m);
  for i:=1 to m do
  begin
    readln(l,r);
    if (l>lim) then begin writeln(0); continue; end;
    r:=min(r,lim);
    writeln(sum[r]-sum[l-1]);
  end;
end.