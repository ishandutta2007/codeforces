#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	ll s,r;
	bool operator<(const node c)const{
		return r>c.r;
	}
}k[100005];

ll n,m;
ll now[100005],cnt[100005],sum[100005];

int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&k[i].s,&k[i].r);
	sort(k+1,k+n+1);
	for(int i=1;i<=n;i++){
		now[k[i].s]+=k[i].r;
		if(now[k[i].s]>0)
			sum[++cnt[k[i].s]]+=now[k[i].s];
		else
			cnt[k[i].s]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,sum[i]);
	cout<<ans<<endl;
	return 0;
}