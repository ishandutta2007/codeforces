#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

string s;
int n,a[N];
void work() {
	int cnt=0;
	cin>>n>>s;
	for (int i=1;i<=n+n;i++) {
		a[i]=s[i-1]=='1';
		cnt+=a[i];
	}
	if (cnt&1) {
		cout<<"-1\n";
		return;
	}
	vector<int>p;
	for (int i=1;i<=n;i++) {
		if (a[i*2-1]^a[i*2]) {
			if (a[i*2]==(p.size()&1)) {
				p.emplace_back(i*2);
			} else {
				p.emplace_back(i*2-1);
			}
		}
	}
	cout<<p.size()<<' ';
	for (int i:p) {
		cout<<i<<' ';
	}
	cout<<"\n";
	for (int i=1;i<=n;i++) {
		cout<<i*2<<" \n"[i==n];
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