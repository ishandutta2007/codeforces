#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m;
char a[MN][MN];
int f[MN][MN];
ll ans;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%s",a[i]+1);
	F(i,1,n)F(j,1,m){
		f[i][j]=1;
		if(2<i&&1<j&&j<m&&a[i][j]==a[i-1][j]&&a[i][j]==a[i-1][j-1]&&a[i][j]==a[i-1][j+1]&&a[i][j]==a[i-2][j]){
			f[i][j]=min({f[i-1][j-1],f[i-1][j+1],f[i-2][j]})+1;
		}
		ans+=f[i][j];
	}
	printf("%lld\n",ans);
	return 0;
}