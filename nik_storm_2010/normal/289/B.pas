uses math;
var
    a:array[1..10000] of longint; ans1,ans2,n,m,d,i,j:longint;


procedure quicksort(l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[random(r-l+1)+l];
  while i<=j do
    begin
      while a[i]<d do inc(i);
      while a[j]>d do dec(j);
      if i<=j then
        begin
          w:=a[i]; a[i]:=a[j]; a[j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n,m,d);
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[(i-1)*m+j]);
      readln;
    end;
  randomize; quicksort(1,n*m);
  for i:=1 to n*m do
    if (a[i]-a[1]) mod d<>0 then
    begin
      writeln(-1); halt;
    end;
  if n*m=1 then begin writeln(0); halt end;
  ans1:=0; ans2:=0;
  for i:=1 to n*m do
    begin
      ans1:=ans1 + (abs(a[i]-a[(n*m) div 2]) div d);
      ans2:=ans2 + (abs(a[i]-a[(n*m) div 2+1]) div d);
    end;
  writeln(min(ans1,ans2));

end.