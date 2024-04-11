var
    a:array[1..100000] of int64; bad:array[1..100000,0..2] of longint;
      answer,nom,n,i:longint; k:int64;


procedure quicksort(l,r:longint);
var i,j:longint; d,w:int64;
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


procedure dichotomy(c:int64; var nom:longint);
var l,m,r:longint;
begin
  l:=1; r:=n; nom:=-1;
  while r-l>1 do
    begin
      m:=(r+l) div 2;
      if a[m]>c then r:=m else l:=m;
    end;
  if a[l]=c then nom:=l; if a[r]=c then nom:=r;
end;


begin

  readln(n,k);
  if k=1 then begin writeln(n); halt; end;
  for i:=1 to n do read(a[i]);
  randomize; quicksort(1,n);
  for i:=1 to n do
    begin
      dichotomy(a[i]*k,nom); if nom<>-1 then
        begin
          inc(bad[i,0]); bad[i,bad[i,0]]:=nom;
          inc(bad[nom,0]); bad[nom,bad[nom,0]]:=i;
        end;
    end;
  answer:=n;
  for i:=1 to n do
    if bad[i,0]=2 then
    begin
      bad[i,0]:=0; bad[bad[i,1],0]:=0;
      if bad[bad[i,2],0]=2 then bad[bad[i,2],1]:=bad[bad[i,2],2];
      dec(bad[bad[i,2],0]); dec(answer);
    end;
  for i:=1 to n do
    if bad[i,0]<>0 then
    begin
      dec(answer); bad[i,0]:=0; bad[bad[i,1],0]:=0;
    end;
  writeln(answer);

end.