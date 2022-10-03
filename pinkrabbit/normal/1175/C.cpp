#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k,t;
int a[MN],b[MN],f[MN],g[MN];
int main(){
	scanf("%d",&t);
	while(t--){
		int s=1e9+7,x=0;
		scanf("%d%d",&n,&k);
		F(i,1,n)scanf("%d",a+i);
		if(!k){printf("%d\n",a[1]);continue;}
		F(i,k+1,n)if(s>a[i]-a[i-k])s=a[i]-a[i-k],x=(a[i]+a[i-k])/2;
		printf("%d\n",x);
	}
	return 0;
}