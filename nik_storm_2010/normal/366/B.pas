var
  a:array[1..200000] of longint;
  ans,sum,nom,n,k,i,j:longint;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  ans:=maxlongint;
  for i:=1 to k do
  begin
    sum:=0;
    for j:=0 to n div k-1 do sum:=sum+a[i+j*k];
    if (sum<ans) then begin ans:=sum; nom:=i; end;
  end;
  writeln(nom);
end.