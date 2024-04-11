uses math;
var
  a,b,s:array[0..32] of int64; ans,n,m,x,y:int64; i,j:longint;


begin

  s[0]:=1; for i:=1 to 30 do s[i]:=s[i-1]*2;
  readln(n,m);
  for i:=1 to n do
  begin
    read(x);
    for j:=0 to 30 do if x and (1 shl j)<>0 then inc(a[j]);
  end;
  for i:=1 to m do begin read(x); inc(b[x]); end;
  ans:=0;
  for i:=0 to 30 do
  begin
    a[i]:=s[i]*a[i]; x:=1;
    for j:=0 to i do
    begin
      y:=min(b[j],a[i] div x);
      ans:=ans+y; b[j]:=b[j]-y; a[i]:=a[i]-y*x;
      x:=x*2;
    end;
  end;
  writeln(ans);

end.