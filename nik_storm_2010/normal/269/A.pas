var
    a,k:array[1..100000] of longint; middle,left,right,n,i:longint;


procedure quicksort(l,r:longint);
var tmp,i,j,d:longint;
begin
  i:=l; j:=r; d:=k[random(r-l+1)+l];
  while i<=j do
    begin
      while k[i]<d do inc(i);
      while k[j]>d do dec(j);
      if i<=j then
        begin
          tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
          tmp:=k[i]; k[i]:=k[j]; k[j]:=tmp;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


function maybe(tek:longint):boolean;
var pred,now,i,j:longint;
begin
  if k[n]>=tek then exit(false);
  now:=1; pred:=tek;
  for i:=n downto 1 do
    begin
      for j:=1 to abs(pred-k[i]) do
        if now>1000000000 then break else now:=now*4;
      pred:=k[i];
      if a[i]>now then exit(false);
    end;
  exit(true);
end;


begin

  readln(n); for i:=1 to n do readln(k[i],a[i]);
  randomize; quicksort(1,n);
  left:=1; right:=maxlongint div 2;
  while right-left>1 do
    begin
      middle:=(right+left) div 2;
      if maybe(middle) then right:=middle else left:=middle;
    end;
  if maybe(left) then writeln(left) else writeln(right);

end.