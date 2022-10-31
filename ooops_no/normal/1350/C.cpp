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

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<bool> simple(N + 100, 1);

int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	simple[0] = simple[1] = 0;
	for (int i = 1; i <= N; i++){
        if (simple[i]){
            for (int j = i * i; j <= N; j += i){
                simple[j] = 0;
            }
        }
	}
	vector<vector<int>> a(N);
	for (int i = 0; i < n; i++) {
		if (simple[v[i]]) {
			a[v[i]].pb(1);
		}
		else {
			int j = 2, k = v[i];
			while (k > 1) {
                if (simple[k]) j = k;
                if (!simple[j]){
                    j++;
                    continue;
                }
				int cnt = 0;
				while (k % j == 0) {
					k /= j;
					cnt++;
				}
				if (cnt != 0) {
					a[j].pb(cnt);
				}
				j++;
			}
		}
	}
	int ans = 1;
	for (int i = 2; i < N; i++) {
		if (a[i].size() == n - 1) {
			sort(a[i].begin(), a[i].end());
			ans *= binpow(i, a[i][0]);
		}
		if (a[i].size() == n) {
			sort(a[i].begin(), a[i].end());
			ans *= binpow(i, max(a[i][0], a[i][1]));
		}
	}
	cout << ans << endl;
	return 0;
}