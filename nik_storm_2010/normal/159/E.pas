var
  a,b,c,d,nom,m1,m2:array[0..200000] of int64; ans,sum,kol:int64; n,i,j,t1,t2,l1,l2,c1,c2:longint;


procedure quicksort(l,r:longint);
var i,j,d1,d2,w:longint;
begin
  i:=l; j:=r; w:=random(r-l+1)+l; d1:=a[w]; d2:=b[w];
  while i<=j do
  begin
    while (a[i]<d1) or ((a[i]=d1)and(b[i]>d2)) do inc(i);
    while (a[j]>d1) or ((a[j]=d1)and(b[j]<d2)) do dec(j);
    if i<=j then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      w:=b[i]; b[i]:=b[j]; b[j]:=w;
      w:=c[i]; c[i]:=c[j]; c[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n); for i:=1 to n do begin readln(a[i],b[i]); c[i]:=i; end;
  randomize; quicksort(1,n);
  i:=1;
  while i<=n do
  begin
    sum:=0; kol:=0;
    for j:=i to n+1 do
      if a[i]=a[j] then
      begin
        inc(kol); sum:=sum+b[j];
        if d[kol]<sum then begin  d[kol]:=sum; nom[kol]:=a[i]; end;
      end
      else begin i:=j; break; end;
  end;
  i:=1; ans:=0;
  while i<=n do
  begin
    sum:=0; kol:=0;
    for j:=i to n+1 do
      if a[i]=a[j] then
      begin
        inc(kol); sum:=sum+b[j];
        if (d[kol+1]<>0) and (nom[kol+1]<>a[i]) and (d[kol+1]+sum>ans) then
        begin
          ans:=d[kol+1]+sum;
          l1:=kol; c1:=a[i]; l2:=kol+1; c2:=nom[kol+1];
        end;
        if (d[kol]<>0) and (nom[kol]<>a[i]) and (d[kol]+sum>ans) then
        begin
          ans:=d[kol]+sum;
          l1:=kol; c1:=a[i]; l2:=kol; c2:=nom[kol];
        end;
        if (d[kol-1]<>0) and (nom[kol-1]<>a[i]) and (d[kol-1]+sum>ans) then
        begin
          ans:=d[kol-1]+sum;
          l1:=kol; c1:=a[i]; l2:=kol-1; c2:=nom[kol-1];
        end;
      end
      else begin i:=j; break; end;
  end;
  writeln(ans); writeln(l1+l2); t1:=0; t2:=0;
  for i:=1 to n do
  begin
    if (a[i]=c1) and (t1<>l1) then begin inc(t1); m1[t1]:=c[i]; end;
    if (a[i]=c2) and (t2<>l2) then begin inc(t2); m2[t2]:=c[i]; end;
  end;
  if l1=l2 then begin for i:=1 to l1 do write(m1[i],' ',m2[i],' '); end;
  if l1<l2 then begin for i:=1 to l1 do write(m2[i],' ',m1[i],' '); write(m2[l2]); end;
  if l1>l2 then begin for i:=1 to l2 do write(m1[i],' ',m2[i],' '); write(m1[l1]); end;

end.