const
  ll=1000;
var
  a:array[1..ll,1..ll] of int64;
  sumn,summ:array[1..ll] of int64;
  c1,c2,now:int64;
  n,m,i,j,x,y:longint;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(a[i,j]);
      sumn[i]:=sumn[i]+a[i,j];
      summ[j]:=summ[j]+a[i,j];
    end;
    readln;
  end;
  c1:=trunc(1e18);
  for i:=0 to n do
  begin
    now:=0;
    for j:=1 to n do now:=now+sumn[j]*(4*j-2-4*i)*(4*j-2-4*i);
    if (now<c1) then begin c1:=now; x:=i; end;
  end;
  c2:=trunc(1e18);
  for i:=0 to m do
  begin
    now:=0;
    for j:=1 to m do now:=now+summ[j]*(4*j-2-4*i)*(4*j-2-4*i);
    if (now<c2) then begin c2:=now; y:=i; end;
  end;
  writeln(c1+c2);
  writeln(x,' ',y);
end.