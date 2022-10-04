#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=301010;
pair<int,ll> a[N];
int main(){
	int n;scanf("%d",&n);
	ll sum=0;
	for(int i=0;i<n;i++){
		int x;ll y;scanf("%d%lld",&x,&y);
		a[i]={x,y};
		sum+=x;
	}
	if(sum>0)for(int i=0;i<n;i++)a[i].first*=-1;
	ll ans=0;
	for(int i=62;i--;){
		ll s=0;
		for(int j=0;j<n;j++)if(__builtin_ctzll(a[j].second)==i)s+=a[j].first;
		if(s<0){
			ans|=1LL<<i;
			for(int j=0;j<n;j++)if(a[j].second&1LL<<i)a[j].first=-a[j].first;
		}
	}
	printf("%lld\n",ans);
}