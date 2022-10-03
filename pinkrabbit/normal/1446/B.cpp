#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 5005
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
char a[MN],b[MN];
int f[MN][MN],ans;
int main(){
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	F(i,1,n)F(j,1,m){
		f[i][j]=max({0,f[i-1][j]-1,f[i][j-1]-1,f[i-1][j-1]+4*(a[i]==b[j])-2});
//		printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		ans=max(ans,f[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}