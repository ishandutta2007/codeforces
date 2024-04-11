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
int n,m,k;
int a[MN],b[MN],c[MN],per[MN];
int pa[MN];int fp(int x){return pa[x]?pa[x]=fp(pa[x]):x;}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m)scanf("%d%d%d",a+i,b+i,c+i),per[i]=i;
	F(i,1,n)pa[i]=0;
	sort(per+1,per+m+1,[](int i,int j){return c[i]<c[j];});
	ll ans=infll;
	int w=n;
	F(id,1,m)if(c[per[id]]<=k){
		int i=per[id];
		int u=fp(a[i]),v=fp(b[i]),x=c[i];
		if(u!=v)pa[v]=u,--w;
		if(w==1)ans=min(ans,(ll)(k-x));
	}
	if(w!=1){
		ll sx=0;
		F(id,1,m)if(c[per[id]]>k){
			int i=per[id];
			int u=fp(a[i]),v=fp(b[i]),x=c[i];
			if(u!=v)pa[v]=u,--w,sx+=x>k?x-k:0;
			if(w==1){
				ans=min(ans,sx);
				break;
			}
		}
	}else{
		F(id,1,m)if(c[per[id]]>k)ans=min(ans,(ll)(c[per[id]]-k));
	}
	printf("%lld\n",ans);
}	return 0;
}