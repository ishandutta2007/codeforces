uses
  math;
const
  ll=300000;
var
  a:array[1..ll] of longint;
  c:array[1..ll] of char;
  d,cnt,i,j:longint;
  s:ansistring;

begin
  readln(s);
  d:=length(s);
  i:=1;
  while (i<=d) do
  begin
    j:=i;
    while (j<=d) and (s[i]=s[j]) do inc(j);
    inc(cnt);
    a[cnt]:=j-i;
    c[cnt]:=s[i];
    i:=j;
  end;
  for i:=1 to cnt do a[i]:=min(a[i],2);
  for i:=1 to cnt-1 do if (a[i]=2) and (a[i+1]=2) then dec(a[i+1]);
  for i:=1 to cnt do for j:=1 to a[i] do write(c[i]);
end.