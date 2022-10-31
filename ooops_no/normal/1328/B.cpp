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
#define int long long
#define ld long double
#define ll long long

mt19937 rnd(51);

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s = "";
		int cnt = 2;
		for (int i = 0; i < n; i++) {
			if (cnt == 0) {
				s += 'a';
				continue;
			}
			if (cnt == 2) {
				int p = (n - i - 1);
				p = p * (p - 1) / 2;
				if (k > p) {
					s += 'b';
					k -= p;
					cnt--;
				}
				else {
					s += 'a';
				}
			}
			else if (cnt == 1) {
				int p = (n - i);
				if (k == p) {
					s += 'b';
					k = 0;
				}
				else {
					s += 'a';
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}