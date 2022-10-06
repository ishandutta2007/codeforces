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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k;
pii a[MN];
priority_queue<int>pq;
ll ans,sum;
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",&a[i].fi);
	F(i,1,n)scanf("%d",&a[i].se),a[i].se*=-1;
	sort(a+1,a+n+1);
	F(i,1,n)a[i].se*=-1;
//	F(i,1,n)printf("(%d,%d), ",a[i].fi,a[i].se);puts("");
	pq.push(a[1].se);sum+=a[1].se;
	F(i,2,n){
//		printf("%d\n",i);
		int dif=a[i].fi-a[i-1].fi,c=0;
		while(dif&&!pq.empty()){
			int t=pq.top();
//			printf("t=%d\n",t);
			ans+=(ll)(c++)*t;
			pq.pop();sum-=t;
			--dif;
		}ans+=sum*(a[i].fi-a[i-1].fi);
		pq.push(a[i].se);sum+=a[i].se;
	}
	int c=0;
	while(!pq.empty()){
		int t=pq.top();
		ans+=(ll)(c++)*t;
		pq.pop();
	}
	printf("%lld\n",ans);
}	return 0;
}