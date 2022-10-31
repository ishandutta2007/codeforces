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

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	int now = 1, cnt = 0;
	while (now <= k) {
		now *= 2, cnt++;
	}
	cnt++;
	vector<vector<int>> v(2, vector<int>(3));
	v[0][0] = (1 << cnt) - 1;
	v[1][0] = (1 << (cnt - 1));
	v[0][1] = (1 << (cnt - 1)) - 1;
	v[1][1] = v[0][0];
	v[1][2] = k;
	cout << 2 << " " << 3 << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}