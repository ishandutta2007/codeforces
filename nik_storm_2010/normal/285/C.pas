var
    a:array[1..500000] of longint; answer,n,i:int64; tek:longint;


procedure quicksort(l,r:int64);
var i,j,d,w:int64;
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

  readln(n); for tek:=1 to n do read(a[tek]);
  randomize; quicksort(1,n);
  answer:=0; i:=1;
  while i<=n do
    begin
      answer:=answer+abs(i-a[i]);
      inc(i);
    end;
  writeln(answer);

end.