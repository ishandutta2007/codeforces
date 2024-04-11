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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k;
int a[MN];
int v[MN],c[MN];ll ans[MN];
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
//	F(i,1,n)printf("%d,",a[i]);puts("");
	map<int,int>mp;
	F(i,1,n)++mp[a[i]];
	F(i,1,n)if(mp[a[i]]>=k)return puts("0"),0;
	for(auto p:mp)++m,v[m]=p.fi,c[m]=p.se;
//	F(i,1,m)printf("(%d,%d),",v[i],c[i]);puts("");
	ll cnt=0,sum=0;
	F(i,1,m){
		ans[i]+=(ll)(v[i]-1)*cnt-sum;
		sum+=(ll)v[i]*c[i];
		cnt+=c[i];
	}
	cnt=0,sum=0;
	dF(i,m,1){
		ans[i]+=sum-(ll)(v[i]+1)*cnt;
		sum+=(ll)v[i]*c[i];
		cnt+=c[i];
	}
	F(i,1,m)ans[i]+=k-c[i];
//	F(i,1,m)printf("%lld,",ans[i]);puts("");
	ll ans1=0,ans2=0;
	int pos=k;
	while(pos<n&&a[pos+1]==a[k])++pos;
	F(i,1,pos)ans1+=a[pos]-a[i];
	ans1-=pos-k;
	pos=n-k+1;
	while(pos>1&&a[pos-1]==a[n-k+1])--pos;
	dF(i,n,pos)ans2+=a[i]-a[pos];
	ans2-=(n-pos+1)-k;
	printf("%lld\n",min({*min_element(ans+1,ans+m+1),ans1,ans2}));
	return 0;
}