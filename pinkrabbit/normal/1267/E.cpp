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
int n,m,q,k;
int a[MM][MN],b[MM],pp[MM];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,m)F(j,1,n)scanf("%d",&a[i][j]);
	int ans=n+1,p=0;
	F(j,1,n-1){
		int w=0;
		F(i,1,m)w+=b[i]=a[i][n]-a[i][j];
		sort(b+1,b+m+1),reverse(b+1,b+m+1);
		int z=0;
		while(w>0)w-=b[++z];
		if(z<ans)ans=z,p=j;
	}
	printf("%d\n",ans);{
		int w=0;
		F(i,1,m)w+=b[i]=a[i][n]-a[i][p],pp[i]=i;
		sort(pp+1,pp+m+1,[](int i,int j){return b[i]>b[j];});
		F(i,1,ans)printf("%d ",pp[i]);puts("");
	}
}	return 0;
}