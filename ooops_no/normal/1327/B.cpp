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
		vector<set<int>> v(n);
		map<int, vector<int>> del;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int a;
				cin >> a;
				v[i].insert(a);
				del[a].pb(i);
			}
		}
		int qq = -1;
		set<int> kek;
		for (int i = 1; i <= n; i++) {
			kek.insert(i);
		}
		for (int i = 0; i < n; i++) {
			if (v[i].size() != 0) {
				int p = *v[i].begin();
				for (auto to : del[p]) {
					v[to].erase(p);
				}
				kek.erase(p);
			}
			else {
				qq = i;
			}
		}
		if (qq != -1 && kek.size() != 0) {
			cout << "IMPROVE" << endl;
			cout << qq + 1 << " " << *kek.begin() << endl;
		}
		else {
			cout << "OPTIMAL" << endl;
		}
	}
	return 0;
}