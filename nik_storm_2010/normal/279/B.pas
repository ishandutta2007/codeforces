var
    a,f:array[0..100000] of longint; ans,tek,n,t,i:longint;


procedure dix(nom:longint; var tek:longint);
var l,r,m:longint;
begin
  l:=nom; r:=n;
  while r-l>1 do
    begin
      m:=(r+l) div 2;
      if f[m]-f[nom-1]>t then r:=m else l:=m;
    end;
  if f[r]-f[nom-1]<=t then tek:=r-nom+1 else
  if f[l]-f[nom-1]<=t then tek:=l-nom+1 else tek:=0;
end;


begin

  readln(n,t); ans:=0;
  for i:=1 to n do begin read(a[i]); f[i]:=f[i-1]+a[i]; end;
  for i:=1 to n do
    begin
      dix(i,tek);
      if tek>ans then ans:=tek;
    end;
  writeln(ans);

end.