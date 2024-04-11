var
  ans,c,d,n,m,i,cur,ost,k:longint;

begin
  readln(c,d);
  readln(n,m);
  readln(k);
  k:=n*m-k;
  if (k<=0) then begin writeln(0); halt; end;
  ans:=maxlongint;
  for i:=0 to 10000 do
  begin
    cur:=i*c;
    ost:=k-n*i;
    if (ost>0) then cur:=cur+d*ost;
    if (ans>cur) then ans:=cur;
  end;
  writeln(ans);
end.