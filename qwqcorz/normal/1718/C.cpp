#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,Q,a[N];
vector<int>split(int n) {
	vector<int>ret;
	for (int i=2;i*i<=n;i++) {
		if (n%i==0) {
			ret.push_back(i);
			while (n%i==0) {
				n/=i;
			}
		}
	}
	if (n>1) {
		ret.push_back(n);
	}
	return ret;
}
void work() {
	cin>>n>>Q;
	auto fac=split(n);
	int m=fac.size();
	vector<vector<ll>>sum(m);
	for (int i=0;i<m;i++) {
		sum[i].resize(fac[i]=n/fac[i]);
	}
	for (int i=0;i<n;i++) {
		cin>>a[i];
		for (int j=0;j<m;j++) {
			sum[j][i%fac[j]]+=a[i];
		}
	}
	multiset<ll>S;
	for (int i=0;i<m;i++) {
		for (int j=0;j<fac[i];j++) {
			S.insert(sum[i][j]*fac[i]);
		}
	}
	cout<<*S.rbegin()<<"\n";
	while (Q--) {
		int x,y;
		cin>>x>>y;
		x--;
		for (int i=0;i<m;i++) {
			S.erase(S.find(sum[i][x%fac[i]]*fac[i]));
			sum[i][x%fac[i]]+=y-a[x];
			S.insert(sum[i][x%fac[i]]*fac[i]);
		}
		a[x]=y;
		cout<<*S.rbegin()<<"\n";
	}
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