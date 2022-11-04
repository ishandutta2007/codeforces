#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;



int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	//ifstream cin(".in");
	//ofstream cout(".out");
	int i, n, m;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	if(m == 0) {
		for(i = 0; i < n; i++) {
			cout << (int)5e8 + i * (2 * n + 5) << " ";
		}
		return 0;
	}

	auto Get = [&](int x) {
		int k = x / 2; 
		if(x & 1) {
			// 2 * 0 + 1 + ... + 2 * (k - 1) - 1
			// k * (k - 1) + k = k ^ 2
			return k * k;
		}
		else {
			// 2 * 1 + ... + 2 * (k - 1)
			// (k - 1) * k
			return k * (k - 1);
		}
	};

	int k = 1;
	while(k <= n + 1 && Get(k) <= m) {
		k++;
	}
	k--;
	m -= Get(k);
	if(k > n || (k == n && m > 0)) {
		cout << -1;
		return 0;
	}
	vector <int> sol(n + 1);
	for(i = 1; i <= k; i++) {
		sol[i] = i;
	}
	if(k < n) {
		vector <int> fr(2 * k + 1);
		for(i = 1; i <= k; i++) {
			for(int j = i + 1; j <= k; j++) {
				fr[sol[i] + sol[j]]++;
			}
		}
		for(i = 2 * k; i >= 1; i--) {
			if(fr[i] == m) {
				sol[k + 1] = i;
				break;
			}
		}
		if(k + 2 <= n) {
			sol[k + 2] = 5e8;
			for(i = k + 3; i <= n; i++) {
				sol[i] = sol[i - 1] + 2 * n + 5;
			}
		}
	}
	/*int ans = 0;
	for(int a = 1; a <= n; a++) {
		for(int b = a + 1; b <= n; b++) {
			for(int c = b + 1; c <= n; c++) {
				ans += (sol[a] + sol[b] == sol[c]);
			}
		}
	}
	assert(ans == aux);*/
	for(i = 1; i <= n; i++) {
		cout << sol[i] << " ";
	}

	return 0;
}