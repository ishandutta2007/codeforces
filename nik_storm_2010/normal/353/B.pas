var
  a,b,ans,c:array[1..500] of longint;
  bad:array[1..500] of boolean;
  k1,k2,n,i,x,ou:longint;

begin
  readln(n);
  k1:=0;
  n:=n*2;
  for i:=1 to n do
  begin
    read(c[i]);
    if (a[c[i]]=0) then
    begin
      a[c[i]]:=1;
      inc(k1);
    end
      else
    begin
      if (b[c[i]]=0) then begin inc(k2); dec(k1); end else bad[i]:=true;
      b[c[i]]:=1;
    end;
  end;
  x:=k1 div 2;
  ou:=(k2+x)*(k2+k1-x);
  writeln(ou);
  k1:=0;
  for i:=1 to n do
  begin
    if (b[c[i]]=1) then continue;
    if (x>0) then begin ans[i]:=1; dec(x); inc(k1); end else ans[i]:=2;
  end;
  for i:=1 to n do
  begin
    if (abs(b[c[i]])<>1) or (bad[i]) then continue;
    if (b[c[i]]=1) then
    begin
      ans[i]:=1;
      b[c[i]]:=-1;
      inc(k1);
    end
    else ans[i]:=2;
  end;
  for i:=1 to n do if bad[i] then
  begin
    if k1<>n div 2 then begin ans[i]:=1; inc(k1); end else ans[i]:=2;
  end;
  for i:=1 to n do write(ans[i],' ');
end.