var
    a:array[1..2,1..200000] of int64; st,en:array[1..200000] of longint;
      answer:int64; tek,n,k,i,l,r:longint;


procedure quicksort(nom,l,r:longint);
var i,j:longint; d,w:int64;
begin
  i:=l; j:=r; d:=a[nom,random(r-l+1)+l];
  while i<=j do
    begin
      while a[nom,i]<d do inc(i);
      while a[nom,j]>d do dec(j);
      if i<=j then
        begin
          w:=a[nom,i]; a[nom,i]:=a[nom,j]; a[nom,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(nom,i,r);
  if l<j then quicksort(nom,l,j);
end;


begin

  readln(n,k); for i:=1 to n do read(a[1,i]); readln;
  for i:=1 to k do
    begin
      readln(l,r);
      inc(st[l]); inc(en[r]);
    end;
  tek:=0;
  for i:=1 to n do
    begin
      tek:=tek+st[i]; a[2,i]:=tek;
      tek:=tek-en[i];
    end;
  randomize; quicksort(1,1,n); quicksort(2,1,n);
  answer:=0;
  for i:=1 to n do answer:=answer+(a[1,i]*a[2,i]);
  writeln(answer);

end.