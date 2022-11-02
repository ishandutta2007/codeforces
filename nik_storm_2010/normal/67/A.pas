var
  a:array[1..1000] of longint; s:string; n,i:longint;


procedure modify(i:longint);
begin
  if (i=0) or ((s[i]='=')and(a[i]=a[i+1])) or ((s[i]='R')and(a[i]<a[i+1])) or ((s[i]='L')and(a[i]>a[i+1])) then exit;
  inc(a[i]); modify(i-1);
end;


begin

  readln(n); readln(s);
  for i:=1 to n do a[i]:=1;
  for i:=1 to n-1 do
  begin
    if s[i]='=' then a[i+1]:=a[i] else
    if s[i]='R' then a[i+1]:=a[i]+1 else modify(i);
  end;
  for i:=1 to n do write(a[i],' ');

end.