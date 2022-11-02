var
    a:array[1..5,1..100000] of longint; ans:array[0..8] of longint;
      n,m,i:longint;


procedure quicksort(p1,p2,l,r:longint);
var d1,d2,w,i,j:longint;
begin
  w:=random(r-l+1)+l; d1:=a[p1,w]; d2:=a[p2,w]; i:=l; j:=r;
  while i<=j do
    begin
      while (a[p1,i]<d1) or ((a[p1,i]=d1)and(a[p2,i]<d2)) do inc(i);
      while (a[p1,j]>d1) or ((a[p1,j]=d1)and(a[p2,j]>d2)) do dec(j);
      if i<=j then
        begin
          w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
          w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
          w:=a[3,i]; a[3,i]:=a[3,j]; a[3,j]:=w;
          w:=a[4,i]; a[4,i]:=a[4,j]; a[4,j]:=w;
          w:=a[5,i]; a[5,i]:=a[5,j]; a[5,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(p1,p2,i,r);
  if l<j then quicksort(p1,p2,l,j);
end;


begin

  readln(n,m);
  for i:=1 to m do
    begin
      readln(a[1,i],a[2,i]);
      a[3,i]:=a[1,i]-a[2,i];
      a[4,i]:=a[1,i]+a[2,i];
    end;
  randomize;
  quicksort(1,2,1,m);
  for i:=1 to m do
    begin
      if (i<>1) and (a[1,i-1]=a[1,i]) and (a[2,i-1]<a[2,i]) then inc(a[5,i]);
      if (i<>m) and (a[1,i+1]=a[1,i]) and (a[2,i+1]>a[2,i]) then inc(a[5,i]);
    end;
  quicksort(2,1,1,m);
  for i:=1 to m do
    begin
      if (i<>1) and (a[2,i-1]=a[2,i]) and (a[1,i-1]<a[1,i]) then inc(a[5,i]);
      if (i<>m) and (a[2,i+1]=a[2,i]) and (a[1,i+1]>a[1,i]) then inc(a[5,i]);
    end;
  quicksort(3,1,1,m);
  for i:=1 to m do
    begin
      if (i<>1) and (a[3,i-1]=a[3,i]) and (a[1,i-1]<a[1,i]) then inc(a[5,i]);
      if (i<>m) and (a[3,i+1]=a[3,i]) and (a[1,i+1]>a[1,i]) then inc(a[5,i]);
    end;
  quicksort(4,1,1,m);
  for i:=1 to m do
    begin
      if (i<>1) and (a[4,i-1]=a[4,i]) and (a[1,i-1]<a[1,i]) then inc(a[5,i]);
      if (i<>m) and (a[4,i+1]=a[4,i]) and (a[1,i+1]>a[1,i]) then inc(a[5,i]);
    end;
  for i:=1 to m do inc(ans[a[5,i]]);
  for i:=0 to 8 do write(ans[i],' ');

end.