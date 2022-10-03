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
int n,k;char s[MN];
int buk[MN][26];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%s",&n,&k,s+1);
	F(i,1,n)F(j,0,25)buk[i][j]=0;
	F(i,1,n){
		int j=(i-1)%k+1;
		j=min(j,k-j+1);
//		printf("%d,",j);
		++buk[j][s[i]-'a'];
	}
//	puts("");
	int kk=(k+1)/2,ans=0;
	F(i,1,kk){
		int sum=0,mx=0;
		F(j,0,25)sum+=buk[i][j],mx=max(mx,buk[i][j]);
//		printf("(%d,%d)\n",sum,mx);
		ans+=sum-mx;
	}
	printf("%d\n",ans);
}	return 0;
}