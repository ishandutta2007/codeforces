var
    a,f:array[0..100000] of int64; answer,max,num:int64; n,k,i:longint;


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


procedure find(nom:longint; var kol:int64);
var l,m,r:longint;
begin
  l:=1; r:=nom;
  while r-l>1 do
    begin
      m:=(r+l) div 2;
      if ((nom-(m-1))*a[nom])-(f[nom]-f[m-1])<=k then r:=m else l:=m;
    end;
  if ((nom-(l-1))*a[nom])-(f[nom]-f[l-1])<=k
    then kol:=nom-(l-1) else kol:=nom-(r-1);
end;


begin

  readln(n,k); for i:=1 to n do read(a[i]);
  randomize; quicksort(1,n);
  for i:=1 to n do f[i]:=f[i-1]+a[i];
  max:=0; answer:=0;
  for i:=1 to n do
    begin
      find(i,num);
      if num>max then
        begin
          max:=num; answer:=a[i];
        end;
    end;
  writeln(max,' ',answer);

end.