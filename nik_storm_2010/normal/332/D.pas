var
  g,c:array[0..2000,0..2000] of extended; ans,sum:extended; cnt,n,k,i,j:longint;


begin
  readln(n,k);
  for i:=0 to n do c[i,0]:=1;
  for i:=1 to n do for j:=1 to n do c[i,j]:=c[i-1,j]+c[i-1,j-1];
  for i:=1 to n do
  begin
    for j:=i+1 to n do begin read(g[i,j]); g[j,i]:=g[i,j]; end;
    if i<>n then readln;
  end;
  ans:=0;
  for i:=1 to n do
  begin
    sum:=0; cnt:=0;
    for j:=1 to n do if (g[i,j]<>-1) and (i<>j) then inc(cnt);
    for j:=1 to n do
      if g[i,j]<>-1 then sum:=sum+g[i,j]*c[cnt-1,k-1];
    ans:=ans+sum;
  end;
  writeln(trunc(ans/c[n,k]));
end.