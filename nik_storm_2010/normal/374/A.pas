uses
  math;
var
  n,m,i,j,a,b,ans:int64;
  f:boolean;

function check(x,y:int64):int64;
var
  k1,k2:int64;
begin
  k1:=abs(x-i);
  if (k1 mod a<>0) then begin check:=maxlongint; exit; end;
  k1:=k1 div a;
  k2:=abs(y-j);
  if (k2 mod b<>0) then begin check:=maxlongint; exit; end;
  k2:=k2 div b;
  if (k1 mod 2=k2 mod 2) then check:=max(k1,k2) else check:=maxlongint;
end;

begin
  readln(n,m,i,j,a,b);
  f:=false;
  if ((i=1) and (j=1)) then f:=true;
  if ((i=1) and (j=m)) then f:=true;
  if ((i=n) and (j=1)) then f:=true;
  if ((i=n) and (j=m)) then f:=true;
  if (f) then begin writeln(0); exit; end;
  if (i-1<a) and (n-i<a) then begin writeln('Poor Inna and pony!'); exit; end;
  if (j-1<b) and (m-j<b) then begin writeln('Poor Inna and pony!'); exit; end;
  ans:=maxlongint;
  ans:=min(ans,check(1,1));
  ans:=min(ans,check(1,m));
  ans:=min(ans,check(n,1));
  ans:=min(ans,check(n,m));
  if (ans=maxlongint) then writeln('Poor Inna and pony!') else writeln(ans);
end.