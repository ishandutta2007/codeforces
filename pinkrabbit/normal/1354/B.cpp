// Author : PinkRabbit
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
int a[4][MN],b[4][MN];
char s[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1),n=strlen(s+1);
	int ans=n+1;
	F(j,1,3)a[j][0]=-inf;
	F(i,1,n){F(j,1,3)a[j][i]=a[j][i-1];a[s[i]-'0'][i]=i;}
	F(j,1,3)b[j][n+1]=inf;
	dF(i,n,1){F(j,1,3)b[j][i]=b[j][i+1];b[s[i]-'0'][i]=i;}
	F(i,2,n-1){
		int x=s[i]-'0';
		if(x==1)ans=min({ans,b[3][i+1]-a[2][i-1]+1,b[2][i+1]-a[3][i-1]+1});
		if(x==2)ans=min({ans,b[3][i+1]-a[1][i-1]+1,b[1][i+1]-a[3][i-1]+1});
		if(x==3)ans=min({ans,b[1][i+1]-a[2][i-1]+1,b[2][i+1]-a[1][i-1]+1});
	}
	printf("%d\n",ans<=n?ans:0);
}	return 0;
}