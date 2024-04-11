#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define MM 1000005
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
ll a[MN],ans;
set<int>b,c;
int C;
int a1[MN],a2[MN];ll a3[MN];
inline void ANS(int x,int y,ll z){a1[++C]=x,a2[C]=y,a3[C]=z;}
int main(){int x,y,z;
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d%d",&x,&y,&z),a[x]-=z,a[y]+=z;
	F(i,1,n)if(a[i]>0)ans+=a[i];
	F(i,1,n)if(a[i]<0)b.insert(i);else if(a[i]>0)c.insert(i);
	while(!b.empty()||!c.empty()){
		x=*b.begin(),y=*c.begin();
		ll w=min(-a[x],a[y]);
		ANS(x,y,w);
		a[x]+=w,a[y]-=w;
		if(!a[x])b.erase(x);
		if(!a[y])c.erase(y);
	}
	printf("%d\n",C);
	F(i,1,C)printf("%d %d %lld\n",a1[i],a2[i],a3[i]);
	return 0;
}