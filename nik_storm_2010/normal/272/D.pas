var
  a:array[1..2,0..200000] of int64; f:array[0..200000] of int64;
  n,x,i:longint; ans,base:int64;


procedure quicksort(l,r:longint);
var i,j,d1,d2,w:longint;
begin
  i:=l; j:=r; w:=random(r-l+1)+l; d1:=a[1,w]; d2:=a[2,w];
  while i<=j do
  begin
    while (a[1,i]<d1) or ((a[1,i]=d1)and(a[2,i]<d2)) do inc(i);
    while (a[1,j]>d1) or ((a[1,j]=d1)and(a[2,j]>d2)) do dec(j);
    if i<=j then
    begin
      w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
      w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
      inc(i); dec(j);
    end;
  end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n);
  for i:=1 to n do
  begin
    read(x); a[1,i]:=x; a[2,i]:=i;
  end;
  readln;
  for i:=1 to n do
  begin
    read(x); a[1,i+n]:=x; a[2,i+n]:=i;
  end;
  readln(base);
  randomize; quicksort(1,2*n);
  ans:=1;
  for i:=1 to 2*n do if (a[1,i]=a[1,i-1]) then f[i]:=f[i-1]+1 else f[i]:=1;
  for i:=1 to 2*n do
    if (a[1,i]=a[1,i-1]) and (a[2,i]=a[2,i-1])
    then ans:=(ans*((f[i]*(f[i]-1) div 2) mod base)) mod base
    else
    begin
      if (a[1,i]=a[1,i+1]) and (a[2,i]=a[2,i+1]) then continue;
      ans:=(ans*f[i]) mod base;
    end;
  writeln(ans);

end.