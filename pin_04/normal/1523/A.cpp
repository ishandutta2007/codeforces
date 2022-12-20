#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 5; 

int pre[N];
int suf[N];
int a[N];
int n,m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			char c; cin >> c;
			a[i] = (c == '1');
		}

		int cur = -1e9;
		for (int i = 1; i <= n; i++) {
			if (a[i])
				cur = i;
			pre[i] = i - cur;
		}

		cur = 2e9;
		for (int  i = n; i >= 1; i--) {
			if (a[i])
				cur = i;
			suf[i] = cur - i;
		}

		for (int i = 1; i <= n; i++) 
			cout << !((pre[i] > 0 && pre[i] == suf[i]) || min(pre[i], suf[i]) > m);

		cout << "\n";
	}
	return 0;
}