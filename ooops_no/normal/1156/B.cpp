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

bool check(string s) {
	for (int i = 0; i < s.size() - 1; i++) {
		if (abs(s[i] - s[i + 1]) == 1) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	string s, s1 = "";
	cin >> s;
	set<char> st;
	map<char, int> mp;
	for (int i = 0; i < s.size(); i++) {
		st.insert(s[i]);
		mp[s[i]]++;
	}
	for (auto to : st) {
		s1 += to;
	}
	if (check(s1)) {
		for (int i = 0; i < s1.size(); i++) {
			for (int j = 0; j < mp[s1[i]]; j++) {
				cout << s1[i];
			}
		}
		cout << endl;
		return;
	}
	if (s1.size() <= 7) {
		while (next_permutation(s1.begin(), s1.end())) {
			if (check(s1)) {
				for (int i = 0; i < s1.size(); i++) {
					for (int j = 0; j < mp[s1[i]]; j++) {
						cout << s1[i];
					}
				}
				cout << endl;
				return;
			}
		}
		cout << "No answer" << endl;
	}
	else {
		for (int i = 0; i < s1.size(); i += 2) {
			for (int j = 0; j < mp[s1[i]]; j++) {
				cout << s1[i];
			}
		}
		for (int i = 1; i < s1.size(); i += 2) {
			for (int j = 0; j < mp[s1[i]]; j++) {
				cout << s1[i];
			}
		}
		cout << endl;
		return;
	}
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