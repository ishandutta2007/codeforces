#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e6+9;
ll jie[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	jie[0]=1;
	rep(i,1,n+1)jie[i]=i*jie[i-1]%m;
	ll ans=0;
	rep(i,1,n+1){
		ans=(ans+jie[i]*jie[n-i]%m*(n-i+1)%m*(n-i+1)%m)%m; 
	}
	printf("%lld",ans);
}