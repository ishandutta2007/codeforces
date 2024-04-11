#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		pair<int, char> cnt[3];
		cnt[0]={count(s.begin(), s.end(), 'R'), 'P'};
		cnt[1]={count(s.begin(), s.end(), 'P'), 'S'};
		cnt[2]={count(s.begin(), s.end(), 'S'), 'R'};
		sort(cnt, cnt+3);
		string r(s.size(), cnt[2].second);
		cout << r << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/