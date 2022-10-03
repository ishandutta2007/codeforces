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
#define mp make_pair
#define fi first
#define se second
int n;
ll x[MN],y[MN],c[MN],k[MN],ans;
ll f[MN];int v[MN],g[MN];
inline ll d(ll x,ll y){return x<y?y-x:x-y;}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%lld%lld",x+i,y+i);
	F(i,1,n)scanf("%lld",c+i);
	F(i,1,n)scanf("%lld",k+i);
	F(i,1,n)f[i]=c[i],g[i]=0,v[i]=0;
	F(w,1,n){
		int p=0;
		F(j,1,n)if(!v[j]&&(!p||f[j]<f[p]))p=j;
		ans+=f[p];
		v[p]=1;
		F(j,1,n)if(!v[j]&&f[j]>(d(x[p],x[j])+d(y[p],y[j]))*(k[p]+k[j]))
			f[j]=(d(x[p],x[j])+d(y[p],y[j]))*(k[p]+k[j]),g[j]=p;
	}printf("%lld\n",ans);
	int a1=0,a2=0;
	F(i,1,n)if(g[i])++a2;else++a1;
	printf("%d\n",a1);
	F(i,1,n)if(!g[i])printf("%d ",i);
	puts("");
	printf("%d\n",a2);
	F(i,1,n)if(g[i])printf("%d %d\n",g[i],i);
	return 0;
}