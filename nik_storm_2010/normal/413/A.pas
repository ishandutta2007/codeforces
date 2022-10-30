uses
  math;
var
  need,mii,maa,mi,ma,n,m,x,i:longint;

begin
  readln(n,m,mi,ma);
  mii:=+maxlongint;
  maa:=-maxlongint;
  for i:=1 to m do
  begin
    read(x);
    mii:=min(x,mii);
    maa:=max(x,maa);
  end;
  if (mii<mi) or (maa>ma) then begin writeln('Incorrect'); halt; end;
  need:=0;
  if (mii<>mi) then inc(need);
  if (maa<>ma) then inc(need);
  if (need<=n-m) then writeln('Correct') else writeln('Incorrect');
end.