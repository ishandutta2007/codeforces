var a,b,n,m,t,i,j,ans,maxn,maxm:int64;
begin
	readln(n,m,t);
	a:=n mod t;
	b:=m mod t;
	i:=n div t;
	j:=m div t;
	if a=0 then maxn:=n else maxn:=(i+1)*a;
	if b=0 then maxm:=m else maxm:=(j+1)*b;
	ans:=maxn*maxm;
	write(ans);
end.