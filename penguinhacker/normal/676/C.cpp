#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, k, ans=1, pref[100001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> s;
	pref[0] = 0;
	for (int i=0; i<n; ++i)
		pref[i+1] = pref[i] + (s[i] == 'a');
	
	// [lb, rb)
	int lb = 0;
	int rb = 1;

	while (rb < n) {
		if (min(pref[rb+1]-pref[lb], rb+1-lb-(pref[rb+1]-pref[lb])) <= k) {
			rb++;
			ans = max(ans, rb-lb);
		}
		else
			lb++;
	}
	
	cout << ans;
	return 0;
}