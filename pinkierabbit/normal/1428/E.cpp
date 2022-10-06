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
typedef pair<ll,int> pli;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,k;
int a[MN],c[MN];
inline ll calc(int x,int w){
	ll b=x/w;
	int d=x%w;
	//d*(b+1) + (w-d)*b
	return (b+1)*(b+1)*d + b*b*(w-d);
}
priority_queue<pli>pq;
int main(){
	scanf("%d%d",&n,&k),k-=n;
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)pq.push({calc(a[i],1)-calc(a[i],2),i});
	while(k--){
		pli p=pq.top();pq.pop();
		int i=p.se;
		++c[i];
		pq.push({calc(a[i],c[i]+1)-calc(a[i],c[i]+2),i});
	}
	ll ans=0;
	F(i,1,n)ans+=calc(a[i],c[i]+1);
	printf("%lld\n",ans);
	return 0;
}