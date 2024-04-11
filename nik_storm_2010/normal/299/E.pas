var
    del:array[1..1000000] of int64; pred,ans,n,x,y,z,a,b,c:int64;
      i,j,kol:longint;


begin

  readln(n); pred:=round(sqrt(n)); kol:=0;
  for i:=1 to pred do
    if n mod i=0 then
    begin
      inc(kol); del[kol]:=i;
      if (i<>n div i) then begin inc(kol); del[kol]:=n div i; end;
    end;
  if n mod 3<>0 then begin writeln(0); halt; end else n:=n div 3;
  ans:=0;
  for i:=1 to kol do
  if (del[i]>100000) or (del[i]*del[i]*del[i]>n) then continue else
    for j:=i to kol do
    if (del[j]>10000000) or (del[i]*del[j]*del[j]>n) then continue else
    begin
      if n mod (del[i]*del[j])<>0 then continue;
      x:=del[i]; y:=del[j]; z:=n div (x*y);
      a:=(x+y-z) div 2;
      b:=x-a;
      c:=y-a;
      if (a<=0) or (b<=0) or (c<=0) then continue;
      if ((a+b+c)*(a+b+c)*(a+b+c)-(a*a*a)-(b*b*b)-(c*c*c)<>3*n) then continue;
      if (a=b) and (a=c) and (b=c) then ans:=ans+1 else
      if (a=b) or (a=c) or (b=c) then ans:=ans+3 else ans:=ans+6;
    end;
  writeln(ans);

end.