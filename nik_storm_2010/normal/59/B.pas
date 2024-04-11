program storm;
const nMax = 200;
var a:array[1..nMax] of longint;
    del2,nedel2,i,n,kol1,kol2,kol3,kol4:longint;
    max:longint;


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
  while d>a[i]  do inc(i);
  while d<a[j]  do dec(j);
  if i<=j then begin
               w:=a[i]; a[i]:=a[j]; a[j]:=w;
               inc(i); dec(j);
               end;
  end;
 if i<r then qsort(i,r);
 if l<j then qsort(l,j);
end;

procedure outputdata;
begin
 writeln(max);
end;

begin
 inputdata;
 qsort(1,n); del2:=0; nedel2:=0; max:=0;
 for i:=1 to n do
  if a[i] mod 2 = 0 then begin inc(del2); end
                    else begin inc(nedel2); end;
 if (nedel2 mod 2 = 0) and (nedel2<>0) then kol1:=nedel2-1
                                       else kol1:=nedel2;
 if kol1=0 then kol2:=0
           else kol2:=del2;
 kol3:=0; kol4:=0;
 for i:=n downto 1 do
   begin
   if a[i] mod 2 = 0 then
      begin
      if kol4<>kol2 then begin inc(kol4); max:=max+a[i]; end;
      end
                     else
      begin
      if kol3<>kol1 then begin inc(kol3); max:=max+a[i]; end;
      end;
   end;
 outputdata;
end.