#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
ll n,k;int m,q;
ll a[MN];
int main(){
	scanf("%lld%d%lld",&n,&m,&k);
	F(i,1,m)scanf("%lld",a+i);
	int ans=0;
	for(int i=1,j;i<=m;i=j+1){
		j=i;
		while(j<m&&(a[j+1]-i)/k==(a[i]-i)/k)++j;
	//	printf("%d-%d\n",i,j);
		++ans;
	}printf("%d\n",ans);
	return 0;
}