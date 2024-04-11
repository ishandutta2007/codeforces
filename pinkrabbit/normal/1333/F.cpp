#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,b[MN],c[MN],s;
int ans[MN];
int main(){
	scanf("%d",&n);
	dF(i,n/2,1){
		F(j,2,n/i)if(!b[j*i])++s,b[j*i]=1;
		c[i]=s;
		F2(j,c[i+1],c[i])ans[n-j]=i;
	}
	F(i,2,n)printf("%d ",ans[i]);
	return 0;
}