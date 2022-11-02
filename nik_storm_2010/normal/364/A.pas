var
  b,sum:array[0..100000] of int64;
  a,i,j,res,d,ans,all:int64;
  x,y,code:longint;
  s:ansistring;

begin
  readln(a);
  readln(s);
  d:=length(s);
  all:=0;
  for x:=1 to d do val(s[x],b[x],code);
  for x:=1 to d do
  begin
    res:=0;
    for y:=x to d do
    begin
      res:=res+b[y];
      inc(sum[res]);
      inc(all);
    end;
  end;
  if (a=0) then ans:=sum[0]*all+sum[0]*all-sum[0]*sum[0] else
  begin
    ans:=0;
    i:=1;
    while (i*i<=a) do
    begin
      if (a mod i<>0) then begin inc(i); continue; end;
      j:=a div i;
      if (j>100000) then begin inc(i); continue; end;
      if (i=j) then ans:=ans+sum[i]*sum[i] else ans:=ans+sum[i]*sum[j]*2;
      inc(i);
    end;
  end;
  writeln(ans);
end.