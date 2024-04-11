#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 105
#define MM 105
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN],b[MN];
int f[2][MN][MM*MM];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",a+i,b+i);
	int o=0;
	memset(f[0],0xc0,sizeof f[0]);
	f[0][0][0]=0;
	F(i,1,n){
		o^=1;
		memset(f[o],0xc0,sizeof f[o]);
		F(j,0,i-1){
			F(k,0,10000)if(f[o^1][j][k]>=0){
				f[o][j][k]=max(f[o][j][k],f[o^1][j][k]+b[i]);
				f[o][j+1][k+a[i]]=max(f[o][j+1][k+a[i]],f[o^1][j][k]+2*b[i]);
			}
		}
	}
	F(j,1,n){
		int ans=0;
		F(k,0,10000)ans=max(ans,min(f[o][j][k],2*k));
		printf("%.6lf\n",ans/2.);
	}
}	return 0;
}