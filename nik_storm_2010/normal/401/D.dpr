const
  b=18;
  l=1 shl b;
var
  a:array[0..b] of longint;
  f:array[0..l,0..99] of int64;
  good:array[0..1000] of longint;
  lim,mask,ost,used,m,k,i,nn,nmask,j:longint;
  prev:integer;
  n:int64;

begin
  readln(n,m);
  for i:=0 to 1000 do good[i]:=i mod m;
  k:=0;
  while (n<>0) do
  begin
    a[k]:=n mod 10;
    inc(k);
    n:=n div 10;
  end;
  for i:=0 to k-1 do for j:=0 to k-1 do if (a[i]>a[j]) then begin ost:=a[i]; a[i]:=a[j]; a[j]:=ost; end;
  lim:=(1 shl k)-1;
  f[0,0]:=1;
  for mask:=0 to lim-1 do for ost:=0 to m-1 do
  begin
    if (f[mask,ost]=0) then continue;
    prev:=-1;
    for i:=0 to k-1 do
    begin
      if ((mask and (1 shl i))<>0) then continue;
      if (mask=0) and (a[i]=0) then continue;
      if (prev=a[i]) then continue;
      nmask:=mask xor (1 shl i);
      nn:=good[ost*10+a[i]];
      f[nmask,nn]:=f[nmask,nn]+f[mask,ost];
      prev:=a[i];
    end;
  end;
  writeln(f[lim,0]);
end.