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
ll p[MN],q[MN],t[MN],k,x,y;
int a,b;
inline bool chk(int d){
	F(i,1,d)t[i]=q[i];
	sort(t+1,t+d+1,[](ll i,ll j){return i>j;});
	ll sum=0;
	F(i,1,d)sum+=p[i]*t[i];
	return sum>=k;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		F(i,1,n)scanf("%lld",p+i);
		scanf("%lld%d%lld%d%lld",&x,&a,&y,&b,&k),k*=100;
		sort(p+1,p+n+1,[](ll i,ll j){return i>j;});
		F(i,1,n)q[i]=(i%a==0?x:0ll)+(i%b==0?y:0ll);
		int l=1,r=n,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(chk(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}