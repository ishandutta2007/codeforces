uses math;
var
    a:array[1..100000] of int64; leng,high,ans,w,h:int64; n,m,i,j:longint;


begin

  readln(n); for i:=1 to n do read(a[i]);
  readln;  readln(m);
  leng:=0; high:=0;
  for i:=1 to m do
    begin
      readln(w,h); ans:=high;
      for j:=leng+1 to w do ans:=max(ans,a[j]);
      leng:=max(leng,w); high:=ans+h;
      writeln(ans);
    end;

end.