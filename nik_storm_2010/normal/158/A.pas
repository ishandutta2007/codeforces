{ Author - Nikita Sazanovich }
{ Time - O(k) }
{ Memory - O(n) }
{ Solution : implementation }

var
 a : array[1..50] of longint;
  n, k, i : longint;


begin

  readln(n,k);
   for i:=1 to n do read(a[i]);

  i:=1;
   while (i<=n) and (a[i]>0) and (a[i]>=a[k]) do inc(i);
  writeln(i-1);

end.