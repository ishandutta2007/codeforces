uses math;
var
  a:array[1..100] of longint; ans,n,i:longint;


begin

  readln(n); for i:=1 to n do read(a[i]);
  if (n=1) or (n mod 2=0) then begin writeln(-1); halt; end;
  ans:=0;
  for i:=n downto 3 do
  begin
    if a[i]<=0 then continue;
    if odd(i)=false then dec(a[i div 2],a[i])
    else begin dec(a[i-1],a[i]); dec(a[(i-1) div 2],a[i]); end;
    ans:=ans+a[i];
  end;
  writeln(ans+max(0,max(a[1],a[2])));

end.