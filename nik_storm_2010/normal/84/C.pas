uses math;
 var
    a:array[1..3,1..10000] of longint; ans:array[1..10000] of longint;
     n,m,i,nom,x,y,an:longint;



procedure quicksort(l,r:longint);
  var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[1,random(r-l+1)+l];
  while i<=j do
    begin
      while a[1,i]<d do inc(i);
      while a[1,j]>d do dec(j);
      if i<=j then
        begin
          w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
          w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
          w:=a[3,i]; a[3,i]:=a[3,j]; a[3,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


procedure dix(c:longint; var nom:longint);
  var l,r,m:longint;
begin
  l:=1; r:=n;
  while r-l>1 do
    begin
      m:=(l+r) div 2;
      if a[1,m]<c then l:=m else r:=m;
    end;
  if abs(a[1,l]-c)<abs(a[1,r]-c) then nom:=l else nom:=r;
end;


begin

  readln(n);
  for i:=1 to n do
    begin
      readln(a[1,i],a[2,i]);
      a[3,i]:=i; ans[i]:=maxlongint;
    end;
  randomize; quicksort(1,n);

  readln(m);
  for i:=1 to m do
    begin
      readln(x,y); dix(x,nom);

      if (nom<>1) and (sqrt(sqr(a[1,nom-1]-x)+sqr(y))<=a[2,nom-1]) then ans[a[3,nom-1]]:=min(ans[a[3,nom-1]],i);
        if sqrt(sqr(a[1,nom]-x)+sqr(y)) <= a[2,nom] then ans[a[3,nom]]:=min(ans[a[3,nom]],i);
      if (nom<>n) and (sqrt(sqr(a[1,nom+1]-x)+sqr(y))<=a[2,nom+1]) then ans[a[3,nom+1]]:=min(ans[a[3,nom+1]],i);
    end;

  for i:=1 to n do
    if ans[i]<>maxlongint then inc(an) else ans[i]:=-1;
    writeln(an);
  for i:=1 to n do write(ans[i],' ');

end.