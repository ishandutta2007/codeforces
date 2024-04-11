#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define V 1000000
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int p[V+5];
void sieve(int n){
	F(i,2,n){
		if(!p[i]){
			p[i]=i;
			F(j,1,n/i)
				if(!p[i*j])
					p[i*j]=i;
		}
	}
//	F(i,1,n)printf("%d,",p[i]);
}

int n,a[MN],q;
int buk[V+5];
int main(){int tests=1;scanf("%d",&tests);
sieve(V);
while(tests--){
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d",a+i);
		int x=a[i],y=1;
		while(p[x]){
			if(y%p[x])y*=p[x];
			else y/=p[x];
			x/=p[x];
		}
		a[i]=y;
	}
//	F(i,1,n)printf("%d,",a[i]);puts("");
	F(i,1,n)buk[a[i]]=0;
	F(i,1,n)++buk[a[i]];
	int ans0=0,ans1=0;
	F(i,1,n)ans0=max(ans0,buk[a[i]]);
	F(i,1,n)if(a[i]==1||buk[a[i]]%2==0)ans1+=buk[a[i]],buk[a[i]]=0;
	F(i,1,n)ans1=max(ans1,buk[a[i]]);
	scanf("%d",&q);
	F(tq,1,q){
		ll w;
		scanf("%lld",&w);
		if(!w)printf("%d\n",ans0);
		else printf("%d\n",ans1);
	}
}	return 0;
}