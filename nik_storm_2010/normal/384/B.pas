var
  a:array[1..10000] of longint;
  n,m,k,i,j:longint;

begin
  readln(n,m,k);
  for i:=1 to n do for j:=1 to m do read(a[j]);
  writeln((m*(m-1)) div 2);
  for i:=1 to m do for j:=i+1 to m do if (k=0) then writeln(i,' ',j) else writeln(j,' ',i);
end.