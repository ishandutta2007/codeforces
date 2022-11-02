var
  a,b,c,h1,h2:array[0..200000] of longint; min,cnt,n,p,k,i,x,y:longint;


procedure quicksort(l,r:longint);
var i,j,d1,d2,w:longint;
begin
  i:=l; j:=r; w:=random(r-l+1)+l; d1:=a[w]; d2:=b[w];
  while i<=j do
  begin
    while (b[i]<d2) or ((b[i]=d2) and (a[i]>d1)) do inc(i);
    while (b[j]>d2) or ((b[j]=d2) and (a[j]<d1)) do dec(j);
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


procedure swap(i,j:longint);
var w:longint;
begin
  w:=h1[i]; h1[i]:=h1[j]; h1[j]:=w;
  w:=h2[i]; h2[i]:=h2[j]; h2[j]:=w;
end;


procedure add(x,y:longint);
var i:longint;
begin
  inc(cnt); h1[cnt]:=x; h2[cnt]:=y; i:=cnt;
  while (i>1) and (h1[i]<h1[i div 2]) do
  begin
    swap(i,i div 2);
    i:=i div 2;
  end;
end;


procedure out(var x,y:longint);
var i,mi:longint;
begin
  x:=h1[1]; y:=h2[1]; swap(1,cnt); dec(cnt); i:=1;
  while (i*2<=cnt) do
  begin
    mi:=i*2;
    if (i*2+1<=cnt) and (h1[i*2+1]<h1[mi]) then mi:=i*2+1;
    if h1[i]>h1[mi] then begin swap(i,mi); i:=mi; end else break;
  end;
end;


begin
  readln(n,p,k);
  for i:=1 to n do
  begin
    readln(a[i],b[i]);
    c[i]:=i;
  end;
  randomize; quicksort(1,n); cnt:=0;
  for i:=n downto 1+(p-k) do
  begin
    if cnt<k then add(a[i],i) else
    begin
      if h1[1]<a[i] then
      begin
        out(x,y);
        add(a[i],i);
      end;
    end;
  end;
  min:=maxlongint;
  for i:=1 to k do
  begin
    out(x,y);
    write(c[y],' ');
    if y<min then min:=y;
  end;
  if (p=k) then halt;
  cnt:=(p-k);
  for i:=min-1 downto 1 do
  begin
    write(c[i],' '); dec(cnt);
    if cnt=0 then break;
  end;
end.