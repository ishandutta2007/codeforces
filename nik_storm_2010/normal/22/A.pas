program storm;
const nMax = 150;
var a:array[1..nMax] of longint;
    n,max,i,priz:longint;


procedure inputdata;
var i:longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure qsort(l,r:longint);
var i,j,d,w:longint;
begin
 i:=l; j:=r;
 d:=a[(i+j) div 2];
 while i<=j do
  begin
  while d>a[i] do inc(i);
  while d<a[j] do dec(j);
  if i<=j then
             begin
             w:=a[i]; a[i]:=a[j]; a[j]:=w;
             inc(i); dec(j);
             end;
  end;
 if i<r then qsort(i,r);
 if l<j then qsort(l,j);
end;

procedure outputdata;
begin
 if priz=1 then writeln(max)
           else writeln('NO');
end;

begin
 inputdata; max:=0; i:=1; priz:=1;
 qsort(1,n);
 while (a[i]=a[1]) and (i<=n) do inc(i);
 if i=(n+1) then begin priz:=0;  outputdata; end
            else begin max:=a[i]; outputdata; end;
end.