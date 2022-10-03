#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,ans;
int a[MN],b[MN],c[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){int x;
	scanf("%d",&n),m=0,ans=inf;
	F(i,1,n)c[i]=b[i]=a[i]=0;b[n+1]=0;
	F(i,1,n)scanf("%d",&x),++a[x];
	F(i,1,n)if(a[i]){++m;F(j,1,a[i]+1)if(a[i]>=((a[i]-1)/j+1)*(j-1))++b[j],c[j]+=(a[i]-1)/j+1;}
	F(i,1,n+1)if(b[i]==m)ans=min(ans,c[i]);
	printf("%d\n",ans);
}	return 0;
}