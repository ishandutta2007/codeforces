const
  l=5000;
var
  sum:array[0..l,0..l] of longint;
  a:array[0..l] of longint;
  ans,cnt,now,all,n,i,j:longint;

function less(i,l,r:longint):longint;
begin
  less:=(r-l+1)-(sum[i,r]-sum[i,l]);
end;

begin
  readln(n);
  for i:=1 to n do begin read(a[i]); inc(a[i]); end;
  for i:=1 to n do
  begin
    now:=0;
    for j:=1 to n do
    begin
      sum[i,j]:=now;
      if (a[j]>a[i]) then inc(now);
    end;
  end;
  for i:=1 to n do all:=all+sum[i,i];
  ans:=maxlongint;
  for i:=1 to n do for j:=i+1 to n do
  begin
    now:=all-sum[i,i]-sum[j,j];
    if (a[i]>a[j]) then inc(now);
    now:=now+sum[j,i]+sum[i,j];
    now:=now-less(i,i,j)+less(j,i,j);
    if (ans>now) then begin ans:=now; cnt:=0; end;
    if (ans=now) then inc(cnt);
  end;
  writeln(ans,' ',cnt);
end.