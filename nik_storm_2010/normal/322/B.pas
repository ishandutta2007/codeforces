uses math;
var
  r,g,b,k1,k2,k3,m,ans,rr,gg,bb,cur:int64;


begin

  readln(r,g,b); ans:=0;
  rr:=r; gg:=g; bb:=b;
  k1:=rr div 3;
  k2:=gg div 3;
  k3:=bb div 3;
  cur:=k1+k2+k3+min(rr mod 3,min(gg mod 3,bb mod 3));
  ans:=max(cur,ans);
  rr:=r-1; gg:=g-1; bb:=b-1;
  k1:=rr div 3;
  k2:=gg div 3;
  k3:=bb div 3;
  cur:=1+k1+k2+k3+min(rr mod 3,min(gg mod 3,bb mod 3));
  ans:=max(ans,cur);
  rr:=r-2; gg:=g-2; bb:=b-2;
  k1:=rr div 3;
  k2:=gg div 3;
  k3:=bb div 3;
  cur:=2+k1+k2+k3+min(rr mod 3,min(gg mod 3,bb mod 3));
  ans:=max(ans,cur);
  writeln(ans);

end.