#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cnt[5];
vector<int> v;

void solve() {
	cin >> n, v.resize(n), cnt[1]=cnt[2]=cnt[3]=cnt[4]=0;
	for (int i=0; i<n; ++i)
		cin >> v[i];
	n/=2;
	int last=v[n];
	v.resize(n);
	while(!v.empty()&&v.back()==last)
		v.pop_back();
	n=v.size();
	if (n<5) {cout << "0 0 0\n"; return;}
	int ind=1;
	for (int i=0; i<n-1; ++i) {
		if (ind==3)
			break;
		++cnt[ind];
		if (v[i]!=v[i+1]&&cnt[ind]>cnt[ind-1])
			++ind;
	}
	cnt[3]=n-cnt[1]-cnt[2];
	if (cnt[1]>=cnt[2]||cnt[1]>=cnt[3])
		cout << "0 0 0\n";
	else
		cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/