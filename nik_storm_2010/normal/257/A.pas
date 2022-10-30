var
    a:array[1..100] of longint; ans,tmp,n,m,k,i,j:longint;


begin

  readln(n,m,k); for i:=1 to n do read(a[i]);
  for i:=1 to n do
    for j:=i+1 to n do
    if a[i]>a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      end;
  ans:=0; m:=m-k;
  while m>0 do
    begin
      if n=0 then begin writeln(-1); halt; end;
      m:=m-(a[n]-1); dec(n); inc(ans);
    end;
  writeln(ans);

end.