uses math;
var
    a,b:array[0..100000] of longint; tek,k1,k2,n,m,k,i,j:longint;


procedure quicksorta(l,r:longint);
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
  if i<r then quicksorta(i,r);
  if l<j then quicksorta(l,j);
end;


procedure quicksortb(l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=b[random(r-l+1)+l];
  while i<=j do
    begin
      while b[i]<d do inc(i);
      while b[j]>d do dec(j);
      if i<=j then
        begin
          w:=b[i]; b[i]:=b[j]; b[j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksortb(i,r);
  if l<j then quicksortb(l,j);
end;


begin

  readln(n,m,k); randomize;
  for i:=1 to n do read(a[i]); quicksorta(1,n);
  for i:=1 to m do read(b[i]); quicksortb(1,m);
  k1:=0; k2:=0; i:=n; j:=m;
  while (i<>0) or (j<>0) do
    begin
      tek:=max(a[i],b[j]);
      while (i>0) and (a[i]=tek) do begin inc(k1); dec(i); end;
      while (j>0) and (b[j]=tek) do begin inc(k2); dec(j); end;
      if k1>k2 then begin writeln('YES'); halt; end;
    end;
  writeln('NO');

end.