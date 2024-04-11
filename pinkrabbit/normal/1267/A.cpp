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
int n,pp[MN*2];
ll a[MN],b[MN],t[MN];
multiset<ll>st;
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%lld%lld%lld",a+i,b+i,t+i),a[i]+=t[i]-1;
	F(i,1,n+n)pp[i]=i;
	sort(pp+1,pp+n+n+1,[](int i,int j){return (i&1?a:b)[(i+1)/2]<(j&1?a:b)[(j+1)/2];});
	ll lb=0,val=0;
	F(id,2,n+n){
		int ii=pp[id-1],i=pp[id];
		ll lpos=(ii&1?a:b)[(ii+1)/2];
		ll rpos=(i&1?a:b)[(i+1)/2];
		if(ii&1)st.insert(t[(ii+1)/2]);
		else st.erase(st.find(t[(ii+1)/2]));
		if(lpos==rpos)continue;
		if(st.empty())continue;
		ll t=*st.begin();
		if(rpos-t<lb)continue;
		ll fp=lb+t>lpos?lb+t:lpos+1;
		ll v=(rpos-fp)/t;
		lb=fp+v*t,val+=v+1;
	}
	printf("%lld\n",val);
}	return 0;
}