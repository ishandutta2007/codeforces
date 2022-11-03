n,k=map(int,input().split())
if k<=2:print(0)
elif n>=k:print((k-1)//2)
else:
	ans=max(n-(k+1)//2+1,0)
	if (k+1)//2==(k-(k+1)//2)and(k+1)//2<=n:ans-=1
	print(max(ans,0))