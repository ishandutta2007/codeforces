uses
  math;
const
  lim=100000+10;
var
  a,sum:array[0..lim] of int64;
  n,i,q:longint;
  power,one,ans,l,r,prev,k,x:int64;

procedure sort(l,r:longint);
var
  i,j:longint;
  d,w:int64;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l];
  repeat
    while (a[i]>d) do inc(i);
    while (a[j]<d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i); dec(j);
    end;
  until (i>j);
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  randomize;
  sort(1,n);
  one:=0;
  for i:=1 to n do
  begin
    sum[i]:=sum[i-1]+a[i];
    one:=one+a[i]*i-a[i];
  end;
  read(q);
  for i:=1 to q do
  begin
    read(power);
    if (power=1) then begin writeln(one); continue; end;
    l:=power; k:=1; x:=1;
    ans:=0;
    while (true) do
    begin
      r:=min(n,x+l);
      ans:=ans+(sum[r]-sum[x])*k;
      if (r=n) then break;
      x:=x+l;
      l:=l*power;
      inc(k);
    end;
    write(ans,' ');
  end;
end.