var
  ans,n,k,m:int64;


begin

  readln(n,k); m:=(n+1) div 2;
  if k<=m then ans:=(k*2)-1 else ans:=(k-m)*2;
  writeln(ans);

end.