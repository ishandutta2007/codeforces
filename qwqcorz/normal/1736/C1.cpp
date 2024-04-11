#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,a[N],b[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	ll ans=0;
	int sum=0;
	multiset<int>S;
	for (int l=n,r=n;l>=1;l--) {
		S.insert(b[l]=a[l]-sum);
		sum--;
		while (*S.begin()+sum<0) {
			S.erase(S.find(b[r--]));
		}
		ans+=r-l+1;
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}