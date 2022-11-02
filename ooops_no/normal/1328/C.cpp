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
		int n;
		cin >> n;
		string s, t = "", k = "";
		cin >> s;
		bool x = 0, x1 = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				t += '0';
				k += '0';
			}
			else if (s[i] == '2') {
				if (!x && !x1) {
					t += '1';
					k += '1';
				}
				else if (!x1) {
					t += '0';
					k += '2';
				}
				else {
					k += '0';
					t += '2';
				}
			}
			else {
				if (!x && !x1) {
					t += '1';
					k += '0';
					x = 1;
				}
				else if (!x1) {
					t += '0';
					k += '1';
				}
				else {
					t += '1';
					k += '0';
				}
			}
		}
		cout << t << endl << k << endl;
	}
	return 0;
}