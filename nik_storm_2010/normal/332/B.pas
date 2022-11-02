var
  a,f,s,p:array[0..200000] of int64; ans,n,k,x,y:int64; i:longint;


begin
  readln(n,k); for i:=1 to n do read(a[i]);
  for i:=1 to n do f[i]:=f[i-1]+a[i];
  for i:=k to n do
  begin
    if f[i]-f[i-k]>s[i-1] then
    begin
      s[i]:=f[i]-f[i-k];
      p[i]:=i-k+1;
    end
    else
    begin
      s[i]:=s[i-1];
      p[i]:=p[i-1];
    end;
  end;
  ans:=0;
  for i:=2*k to n do
    if f[i]-f[i-k]+s[i-k]>ans then
    begin
      ans:=f[i]-f[i-k]+s[i-k];
      x:=p[i-k]; y:=i-k+1;
    end
      else
    begin
      if (f[i]-f[i-k]+s[i-k]=ans) then
      begin
        if (p[i-k]<x) or ((p[i-k]=x) and (i-k+1<y)) then
        begin
          x:=p[i-k]; y:=i-k+1;
        end;
      end;
    end;
  writeln(x,' ',y);
end.