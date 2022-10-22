#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, pref[mxN+1];
string s;
vector<int> oc;

bool ok(int x) {
	int y=oc.size()-x-1;
	for (int i=0; i+y<oc.size(); ++i)
		if (pref[oc[i+y]+1]-pref[oc[i]]<=x)
			return 1;
	return 0;
}

void solve() {
	cin >> s;
	n=s.size();
	oc.clear();
	for (int i=0; i<n; ++i) {
		pref[i+1]=pref[i];
		if (s[i]=='0')
			++pref[i+1];
		else
			oc.push_back(i);
	}
	int lb=0, rb=oc.size();
	while(lb<rb) {
		int mid=(lb+rb)/2;
		if (ok(mid))
			rb=mid;
		else
			lb=mid+1;
	}
	cout << lb << "\n";
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