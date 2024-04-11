#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN][MN],b[MN][MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)F(j,1,n)scanf("%1d",&a[i][j]);
	F(i,1,n)F(j,1,n)scanf("%1d",&b[i][j]);
	F(i,1,n)F(j,1,n)a[i][j]^=b[i][j];
	F(i,1,n)if(a[i][1])F(j,1,n)a[i][j]^=1;
	F(j,1,n)if(a[1][j])F(i,1,n)a[i][j]^=1;
	int ok=1;
	F(i,1,n)F(j,1,n)if(a[i][j])ok=0;
	puts(ok?"YES":"NO");
}	return 0;
}