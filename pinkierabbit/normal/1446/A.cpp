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
int n;
ll W,w[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%lld",&n,&W);
	ll sum=0;
	F(i,1,n){
		scanf("%lld",w+i);
		if(w[i]<=W)sum+=w[i];
	}
	if(sum*2<W){puts("-1");continue;}
	int ok=0;
	F(i,1,n)if(w[i]<=W&&w[i]*2>=W){
		printf("1\n%d\n",i);
		ok=1;
		break;
	}
	if(ok)continue;
	sum=0;
	int c=0;
	F(i,1,n)if(w[i]<=W){
		sum+=w[i],++c;
		if(2*sum>=W){
			printf("%d\n",c);
			F(j,1,i)if(w[j]<=W)printf("%d%c",j," \n"[j==i]);
			ok=1;
			break;
		}
	}
}	return 0;
}