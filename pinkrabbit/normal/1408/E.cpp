#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define MM 200005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,a[MN],b[MN];
int pa[MN*2];
int fp(int x){return pa[x]?pa[x]=fp(pa[x]):x;}
int eu[MM],ev[MM],ew[MM],ep[MM],q;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,m)scanf("%d",b+i);
	F(i,1,n){
		int k;
		scanf("%d",&k);
		while(k--){
			int j;
			scanf("%d",&j);
			++q;
			eu[q]=i;
			ev[q]=n+j;
			ew[q]=a[i]+b[j];
			ep[q]=q;
		}
	}
	sort(ep+1,ep+q+1,[](int i,int j){return ew[i]>ew[j];});
	ll ans=0;
	F(i,1,q){
		int u=eu[ep[i]],v=ev[ep[i]],w=ew[ep[i]];
		if(fp(u)==fp(v)){ans+=w;continue;}
		pa[fp(u)]=fp(v);
	}
	printf("%lld\n",ans);
	return 0;
}