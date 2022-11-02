var
  sum:array[0..200000] of longint;
  ans,nom,n,x,i,k:longint;

begin
  readln(n,k);
  for i:=1 to n do
  begin
    read(x);
    sum[i]:=sum[i-1]+x;
  end;
  ans:=maxlongint;
  for i:=1 to n-k+1 do if (sum[i+k-1]-sum[i-1]<ans) then
  begin
    ans:=sum[i+k-1]-sum[i-1];
    nom:=i;
  end;
  writeln(nom);
end.