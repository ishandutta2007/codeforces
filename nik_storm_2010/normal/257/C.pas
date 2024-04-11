uses math;
var
  x,y,ugol:array[1..100000] of extended; xx,yy,n,i:longint; m:extended;


procedure quicksort(l,r:longint);
var i,j:longint; d,w:extended;
begin
  i:=l; j:=r; d:=ugol[random(r-l+1)+l];
  while i<=j do
  begin
    while ugol[i]<d do inc(i);
    while ugol[j]>d do dec(j);
    if i<=j then
    begin
      w:=ugol[i]; ugol[i]:=ugol[j]; ugol[j]:=w;
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
    readln(x[i],y[i]);
    ugol[i]:=180+arctan2(x[i],y[i])/pi*180;
  end;
  randomize; quicksort(1,n);
  m:=(ugol[1]+360)-ugol[n];
  for i:=1 to n-1 do if ugol[i+1]-ugol[i]>m then m:=ugol[i+1]-ugol[i];
  writeln(360-m:0:6);

end.