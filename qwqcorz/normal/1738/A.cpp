#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int n,t[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>t[i];
	}
	int mn=1e9+7;
	vector<int>a[2];
	for (int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a[t[i]].emplace_back(x);
		mn=min(mn,x);
	}
	ll ans=0;
	if (a[0].size()==a[1].size()) {
		for (int k=0;k<=1;k++) {
			for (int i:a[k]) {
				ans+=i*2;
			}
		}
		ans-=mn;
	} else {
		if (a[0].size()>a[1].size()) {
			swap(a[0],a[1]);
		}
		for (int i:a[0]) {
			ans+=i*2;
		}
		int tot=a[0].size();
		sort(a[1].begin(),a[1].end(),greater<int>());
		for (int i:a[1]) {
			ans+=i;
			if (tot) {
				ans+=i;
				tot--;
			}
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}