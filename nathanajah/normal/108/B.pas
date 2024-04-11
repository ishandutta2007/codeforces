var
n:longint;
a:array[1..100000] of int64;
i:longint;
ganti:boolean;

procedure qsort;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,n);
    end;

begin
readln(n);
for i:=1 to n do
  read(a[i]);
qsort;
for i:=2 to n do
  if (a[i]<2*a[i-1]) and (a[i]>a[i-1]) then
  begin
    ganti:=true;
    break;
  end;
if ganti then writeln('YES') else writeln('NO');
end.