#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	cin >> n;
	vector<int> arr(n + 1);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	vector<ll> hsh(n + 1);
	for(i = 1; i <= n; i++) {
		cin >> arr[i];
		hsh[arr[i]] = (1LL * rng() << 10) + rng();
	}
	
	vector<vector<int>> last(n + 1);
	unordered_map<ll, int> mp;
	mp[0]++;

	vector<int> fr(n + 1);
	vector<ll> pref(n + 1);
	ll ans = 0;
	int pos = 0;

	for(i = 1; i <= n; i++) {
		fr[arr[i]]++;
		if(fr[arr[i]] % 3 == 0) {
			pref[i] = pref[i - 1] - 2LL * hsh[arr[i]];
		}
		else {
			pref[i] = pref[i - 1] + hsh[arr[i]];
		}

		mp[pref[i]]++;
		last[arr[i]].push_back(i);

		int sz = (int)last[arr[i]].size();
		if(sz > 3) {
			while(pos < last[arr[i]][sz - 4]) {
				mp[pref[pos]]--;
				pos++;
			}
		}
		ans += mp[pref[i]] - 1;
	}
	
	cout << ans;
	cerr << ans << "\n";
	
    return 0;
}