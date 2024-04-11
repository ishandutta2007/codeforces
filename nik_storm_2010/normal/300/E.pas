var
    a,simple:array[1..1000000] of int64; k,used:array[1..10000000] of int64;
      middle,right,left,kol,cur,n,i,j:int64; tek:longint;


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


function maybe(cur:int64):boolean;
var tek,num,i:int64;
begin
  i:=1;
  while (i<=kol) and (cur div simple[i]>0) do
    begin
      tek:=simple[i]; num:=0;
      while (cur div tek>0) do
        begin
          num:=num+cur div tek; tek:=tek*simple[i];
        end;
      if k[simple[i]]>num then exit(false); inc(i);
    end;
  if i=kol+1 then maybe:=true else maybe:=false;
end;


begin

  readln(n); for tek:=1 to n do read(a[tek]);
  randomize; quicksort(1,n);
  if a[n]=1 then begin writeln(1); halt; end;
  i:=2; kol:=0;
  while i<=a[n] do
    begin
      if used[i]=0 then
      begin
        j:=i*i; inc(kol); simple[kol]:=i; used[i]:=i;
        while j<=a[n] do
          begin
            if used[j]=0 then used[j]:=i;
            j:=j+i;
          end;
      end;
      inc(i);
    end;
  j:=1;
  for tek:=1 to a[n] do
    begin
      k[tek]:=n-j+1;
      while (j<=n) and (a[j]=tek) do inc(j);
    end;
  for tek:=a[n] downto 2 do
    begin
      if used[tek]=tek then continue;
      k[used[tek]]:=k[used[tek]]+k[tek];
      k[tek div used[tek]]:=k[tek div used[tek]]+k[tek];
    end;
  left:=1; right:=round(1e13);
  while right-left>1 do
    begin
      middle:=(left+right) div 2;
      if maybe(middle) then right:=middle else left:=middle;
    end;
  if maybe(left) then writeln(left) else writeln(right);

end.