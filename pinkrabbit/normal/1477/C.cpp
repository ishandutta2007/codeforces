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
int n,x[MN],y[MN],v[MN],ans[MN];
int cal(int i,int j,int k){return (ll)(x[j]-x[i])*(x[k]-x[j])+(ll)(y[j]-y[i])*(y[k]-y[j])<0;}
ll dis(int i,int j){return (ll)(x[i]-x[j])*(x[i]-x[j])+(ll)(y[i]-y[j])*(y[i]-y[j]);}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",x+i,y+i);
	int p=1;
	v[1]=1;
	ans[1]=1;
	F(i,2,n){
		int w=0;
		F(j,1,n)if(!v[j]&&(!w||dis(p,j)>dis(p,w)))w=j;
		v[w]=1,ans[i]=w,p=w;
	}
	F(i,1,n)printf("%d ",ans[i]);
	return 0;
}