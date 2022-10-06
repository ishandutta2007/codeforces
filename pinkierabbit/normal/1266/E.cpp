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
int n,q;
int a[MN],b[MN];
map<pii,int>mp;
ll ans;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),ans+=a[i];
	scanf("%d",&q);
	F(Q,1,q){
		int x,y,z,w=0;
		scanf("%d%d%d",&x,&y,&z);
		if(mp[{x,y}])w=mp[{x,y}];
		if(w&&--b[w]<a[w])++ans;
		if(z&&++b[z]<=a[z])--ans;
		mp[{x,y}]=z;
		printf("%lld\n",ans);
	}
	return 0;
}