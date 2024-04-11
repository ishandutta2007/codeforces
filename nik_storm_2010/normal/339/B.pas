var
  a:array[1..100000] of int64; n,m,k,x,ans:int64; i:longint;


begin
  readln(n,m); k:=0;
  for i:=1 to m do
  begin
    read(x);
    if (k=0) then
    begin
      inc(k); a[k]:=x;
    end
      else
    begin
      if (a[k]=x) then continue;
      inc(k); a[k]:=x;
    end;
  end;
  ans:=0; x:=1;
  for i:=1 to k do
  begin
    if (x<=a[i]) then ans:=ans+(a[i]-x) else ans:=ans+a[i]+n-x;
    x:=a[i];
  end;
  writeln(ans);
end.