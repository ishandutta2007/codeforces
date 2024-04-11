uses math;
var
  pow,ans:array[0..100] of int64; n,cnt,w:int64; i,j:longint;


function f(t:int64):int64;
begin
  exit(t*(t-1) div 2+(pow[i]-1)*t);
end;


procedure dichotomy;
var l,r,m:int64;
begin
  l:=1; r:=min(maxlongint,n div pow[i]+1);
  while r-l>1 do
  begin
    m:=(l+r) div 2;
    if f(m)<n then l:=m else r:=m;
  end;
  if (l mod 2=1) and (f(l)=n) then begin inc(cnt); ans[cnt]:=l*pow[i]; end else
  if (r mod 2=1) and (f(r)=n) then begin inc(cnt); ans[cnt]:=r*pow[i]; end;
end;


begin

  pow[0]:=1; for i:=1 to 60 do pow[i]:=pow[i-1]*2;
  readln(n);
  for i:=0 to 60 do dichotomy;
  if cnt=0 then writeln(-1) else
  begin
    for i:=1 to cnt do for j:=1 to cnt do
      if ans[i]<ans[j] then
      begin
        w:=ans[i]; ans[i]:=ans[j]; ans[j]:=w;
      end;
    for i:=1 to cnt do writeln(ans[i]);
  end;

end.