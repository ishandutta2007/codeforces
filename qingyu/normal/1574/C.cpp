#include <bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n;
long long a[N],sum;
long long solve(long long x,long long y)
{
	long long cost=5e18;
	int t=lower_bound(a+1,a+n+1,x)-a;
	for(int i=t-1;i<=t;++i){
		if(i>=1&&i<=n)cost=min(cost,max(0ll,x-a[i])+max(0ll,y-(sum-a[i])));
	}
	return cost;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i){	
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	int m;
	cin>>m;
	while(m--){
		long long x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<'\n';
	}
}