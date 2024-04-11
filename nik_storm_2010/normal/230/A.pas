var
    a,b:array[1..1000] of longint; s,n,i:longint;



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
          w:=b[i]; b[i]:=b[j]; b[j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(s,n); for i:=1 to n do readln(a[i],b[i]);
  randomize; quicksort(1,n);

  for i:=1 to n do
    begin
      if a[i]>=s then
        begin
          writeln('NO');
          exit;
        end
          else
        begin
          s:=s+b[i];
        end;
    end;
  writeln('YES');

end.