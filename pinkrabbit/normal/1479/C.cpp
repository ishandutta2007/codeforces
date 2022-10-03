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
int m;
std::vector<int>ans[MN];
int main(){
	puts("YES");
	int l,r;
	scanf("%d%d",&l,&r);
	int n=30;
	F(j,-1,19){
		int u=n-j-1;
		F(k,j+1,19){
			int v=n-k-1;
			ans[++m]={v,u,u==n?1:1<<j};
//			printf("%d %d %d\n",v,u,u==n?1:1<<j);
		}
	}
	if(l==1)ans[++m]={1,n,1},++l;
	int d=r-l+1;
	dF(j,19,0)if(d>>j&1){
		ans[++m]={1,n-j-1,l-1};
		l+=1<<j;
	}
	printf("%d %d\n",n,m);
	F(i,1,m)printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}