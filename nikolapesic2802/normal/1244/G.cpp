#include<bits/stdc++.h>
#define f for(int i=1;i<=n;i++)
long long a[(int)1e6],b[(int)1e6],n,k,s,x=1,y;
int main(){
	std::cin>>n>>k;
	f a[i]=b[i]=i;
	s=k;k-=n*(n+1)/2;y=n;
	if(k<0)return 0*printf("-1\n");
	while(x<y&&k>=y-x)k-=y-x,std::swap(b[x],b[y]),x++,y--;
	if(k&&x<y)std::swap(b[x],b[x+k]),k=0;
	printf("%lld\n",s-k);
	f printf("%d ",a[i]);printf("\n");
	f printf("%d ",b[i]);printf("\n");
}