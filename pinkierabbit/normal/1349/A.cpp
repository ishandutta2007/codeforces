#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k;
vector<int>a[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n){
		int x;
		scanf("%d",&x);
		for(int j=2;j*j<=x;++j)if(x%j==0){
			int c=0;
			while(!(x%j))x/=j,++c;
			a[j].pb(c);
		}if(x>1)a[x].pb(1);
	}
	ll ans=1;
	F(i,1,200000)if(!a[i].empty()){
		sort(a[i].begin(),a[i].end());
//		printf("%d:",i);
//		for(int x:a[i])printf("%d,",x);puts("");
		if((int)a[i].size()<=n-2)continue;
		int x=0;
		if((int)a[i].size()==n-1)x=a[i][0];
		else x=a[i][1];
//		printf("x=%d\n",x);
		while(x--)ans*=i;
	}printf("%lld\n",ans);
	return 0;
}