#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000], cnt[30];

void test_case() {
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int bit=0; bit<30; ++bit)
			if (a[i]&(1<<bit))
				++cnt[bit];
	}
	for (int bit=29; ~bit; --bit) {
		if (cnt[bit]%2==0) continue;
		int x=cnt[bit], y=n-cnt[bit];
		cout << (x%4==3&&y%2==0?"LOSE":"WIN") << '\n';
		return;
	}
	cout << "DRAW\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/