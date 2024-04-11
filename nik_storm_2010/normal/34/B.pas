program storm;
var a:array[1..250] of longint;
    n,sum,m,i:longint;


procedure inputdata;
var i:longint;
begin
 readln(n,m);
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
 writeln(-sum);
end;

begin
 inputdata;
 qsort(1,n); sum:=0;
 for i:=1 to m do if a[i]<0 then sum:=sum+a[i];
 outputdata;
end.