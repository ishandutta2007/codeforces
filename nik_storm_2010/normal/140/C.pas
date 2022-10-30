uses math; const maxn=150000;
var
    heap,tek:array[1..2,1..maxn] of longint; ans:array[1..3,1..maxn] of longint;
      a:array[1..maxn] of longint; answer,last,ma,mi,n,i,j,x,y,z:longint;


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
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


procedure addheap(c,kol:longint);
var tmp,i:longint;
begin
  inc(last); heap[1,last]:=kol; heap[2,last]:=c; i:=last;
  while (i div 2>0) and (heap[1,i]>heap[1,i div 2]) do
    begin
      tmp:=heap[1,i div 2]; heap[1,i div 2]:=heap[1,i]; heap[1,i]:=tmp;
      tmp:=heap[2,i div 2]; heap[2,i div 2]:=heap[2,i]; heap[2,i]:=tmp;
      i:=i div 2;
    end;
end;


procedure modify(nom:longint);
var tmp,ma,j,i:longint;
begin
  i:=nom; dec(heap[1,nom]);
  if heap[1,nom]=0 then
    begin
      heap[1,nom]:=heap[1,last]; heap[2,nom]:=heap[2,last];
      dec(last);
    end;
  while true do
    begin
      ma:=-maxlongint; j:=-1;
      if (i*2<=last) and (ma<heap[1,i*2]) then begin ma:=heap[1,i*2]; j:=i*2; end;
      if (i*2+1<=last) and (ma<heap[1,i*2+1]) then begin ma:=heap[1,i*2+1]; j:=i*2+1; end;
      if (ma=-maxlongint) or (heap[1,nom]>=ma) then break else
        begin
          tmp:=heap[1,i]; heap[1,i]:=heap[1,j]; heap[1,j]:=tmp;
          tmp:=heap[2,i]; heap[2,i]:=heap[2,j]; heap[2,j]:=tmp;
          i:=j;
        end;
    end;
end;


procedure getheap(var a,b,c:longint);
var kol,tmp,i,j,x,z:longint;
begin
  kol:=min(7,last);
  for i:=1 to kol do
    begin
      tek[1,i]:=heap[1,i]; tek[2,i]:=i;
    end;
  for i:=1 to kol do
    for j:=i+1 to kol do
    if (tek[1,i]<tek[1,j]) or ((tek[1,i]=tek[1,j])and(tek[2,i]>tek[2,j])) then
    begin
      tmp:=tek[1,i]; tek[1,i]:=tek[1,j]; tek[1,j]:=tmp;
      tmp:=tek[2,i]; tek[2,i]:=tek[2,j]; tek[2,j]:=tmp;
    end;
  x:=max(tek[2,3],tek[2,2]); x:=max(x,tek[2,1]);
  z:=min(tek[2,3],tek[2,2]); z:=min(z,tek[2,1]);
  a:=heap[2,tek[2,1]]; b:=heap[2,tek[2,2]]; c:=heap[2,tek[2,3]];
  modify(x); modify(tek[2,3]+tek[2,2]+tek[2,1]-x-z); modify(z);
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  randomize; quicksort(1,n);
  last:=0; i:=1;
  while i<=n do
    begin
      j:=i; while a[i]=a[j] do inc(j);
      addheap(a[i],j-i); i:=j;
    end;
  while last>2 do
    begin
      getheap(x,y,z); inc(answer);
      ma:=max(x,y); ma:=max(ma,z); mi:=min(x,y); mi:=min(mi,z);
      ans[1,answer]:=ma; ans[2,answer]:=x-mi+y-ma+z; ans[3,answer]:=mi;
    end;
  writeln(answer);
  for i:=1 to answer do writeln(ans[1,i],' ',ans[2,i],' ',ans[3,i]);

end.