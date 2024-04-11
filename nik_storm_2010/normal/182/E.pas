const
  md=round(1e9)+7;
  ll=3500;
  ln=100;
var
  f:array[0..ll,0..ln,0..1] of longint;
  a,b:array[1..ln] of longint;
  n,l,i,j,k,turn,prev,ans:longint;

begin
  readln(n,l);
  for i:=1 to n do
  begin
    readln(a[i],b[i]);
    inc(f[a[i],i,0]);
    if (a[i]<>b[i]) then inc(f[b[i],i,1]);
  end;
  for i:=1 to l do for j:=1 to n do for turn:=0 to 1 do
  begin
    if (f[i,j,turn]=0) then continue;
    if (turn=0) then prev:=b[j] else prev:=a[j];
    for k:=1 to n do if (k<>j) then
    begin
      if (a[k]=prev) then
      begin
        f[i+a[k],k,0]:=f[i+a[k],k,0]+f[i,j,turn];
        if (f[i+a[k],k,0]>=md) then f[i+a[k],k,0]:=f[i+a[k],k,0]-md;
      end;
      if (a[k]<>b[k]) and (b[k]=prev) then
      begin
        f[i+b[k],k,1]:=f[i+b[k],k,1]+f[i,j,turn];
        if (f[i+b[k],k,1]>=md) then f[i+b[k],k,1]:=f[i+b[k],k,1]-md;
      end;
    end;
  end;
  ans:=0;
  for j:=1 to n do for turn:=0 to 1 do
  begin
    ans:=ans+f[l,j,turn];
    if (ans>=md) then ans:=ans-md;
  end;
  writeln(ans);
end.