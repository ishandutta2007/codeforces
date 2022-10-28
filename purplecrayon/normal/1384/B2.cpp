#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e2+10;

void solve(){
    int n, k, l;
	cin >> n >> k >> l;
	vector<int> d(n+1), safe = { 0 };
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		if (d[i] + k <= l)
			safe.push_back(i);
	}
	safe.push_back(n+1);
	bool ok = true;
	for (size_t i = 1; i < safe.size() && ok; ++i) {
		int tide = k; bool down = true;
		for (int j = safe[i-1] + 1; j < safe[i]; ++j) {
			tide += down ? -1 : +1;
			if (down) tide -= max(0, d[j] + tide - l);
			if (tide < 0 || d[j] + tide > l) { ok = false; break; }
			if (tide == 0) down = false;
		}
	}
	if (ok) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}