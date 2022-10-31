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

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> v(d * 2 + 100), sum(d * 2 + 100);
	for (int i = a; i <= b; i++){
        v[i + b - 1]--, v[i + c]++;
	}
	int now = 0;
	for (int i = v.size() - 2; i > -1; i--){
        now += v[i];
        sum[i] = sum[i + 1] + now;
	}
	int ans = 0;
	for (int i = c; i <= d; i++){
        ans += sum[i + 1];
	}
	cout << ans << endl;
    return 0;
}