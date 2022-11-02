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
		if (n < k) {
			cout << "NO\n";
		}
		else if (n % 2 != k % 2) {
			cout << "NO\n";
		}
		else if (n < k * k) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}