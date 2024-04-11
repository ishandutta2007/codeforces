#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long
#define mp make_pair

mt19937 rnd(51);

int __gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return __gcd(b, a % b);
}

void solve() {
	int a, b, q;
	cin >> a >> b >> q;
	if (a > b) {
		swap(a, b);
	}
	int g = a * b / __gcd(a, b);
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		int ans = 0, kek = r - l + 1;
		if (l <= b - 1) {
			if (r <= b - 1) {
				ans = r - l + 1;
				cout << kek - ans << " ";
				continue;
			}
			else{
                ans += b - l;
			}
		}
		int mn = (l / g + min(1ll, l % g)) * g, mx = r / g * g;
        if (l % g != 0 && mn != g){
            mn -= g;
            mn += b - 1;
            if (mn >= l){
                ans += min(r, mn) - l + 1;
            }
        }
		if (mn > mx){
            cout << kek - ans << " ";
		}
		else {
			ans += (mx - mn) / g * b;
			ans += min(b, r - mx + 1);
			cout << kek - ans << " ";
		}
	}
	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}