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
vector<int> g[N], d(N);
vector<bool> used(N);
vector<int> sz(N);
int ans = 0;
int now[N][2];
int cntt[N][2];

void cnt(int v){
    used[v] = 1;
    sz[v] = 1;
    for (auto to : g[v]){
        if (!used[to]){
            d[to] = d[v] + 1;
            cnt(to);
            sz[v] += sz[to];
        }
    }
}

void dfs(int v){
    now[v][0] = 0;
    cntt[v][0] = 1;
    used[v] = 1;
    vector<pair<pair<int, int>, pair<int,int>>> lol;
    for (auto t : g[v]){
        if (!used[t]){
            dfs(t);
            int f = 0, cnt = 0, s = 0, cnt1 = 0;
            if (now[t][0] != -1e9){
                now[v][1] = max(now[v][1], 0ll);
                now[v][1] += now[t][0] + cntt[t][0];
                s += now[t][0] + cntt[t][0];
                cntt[v][1] += cntt[t][0];
                cnt1 += cntt[t][0];
            }
            if (now[t][1] != -1e9){
                now[v][0] = max(now[v][0], 0ll);
                now[v][0] += now[t][1] + cntt[t][1];
                f += now[t][1] + cntt[t][1];
                cntt[v][0] += cntt[t][1];
                cnt += cntt[t][1];
            }
            lol.pb({{f, cnt}, {s, cnt1}});
        }
    }
    int sum = 0, sum1 = 0, cnt = 0, cnt1 = 0;
    for (int i = 0; i < lol.size(); i++){
        auto to = lol[i];
        sum += to.first.first, cnt += to.first.second;
        sum1 += to.second.first, cnt1 += to.second.second;
    }
    for (int i = 0; i < lol.size(); i++){
        auto to = lol[i];
        sum -= to.first.first, cnt -= to.first.second;
        sum1 -= to.second.first, cnt1 -= to.second.second;
        ans += (to.first.first * cnt + to.first.second * sum) / 2;
        ans += (to.second.first * cnt1 + to.second.second * sum1) / 2;
        ans += (to.first.first * cnt1 + to.first.second * sum1 - cnt1 * to.first.second) / 2 + cnt1 * to.first.second;
        ans += (to.second.first * cnt + to.second.second * sum - cnt * to.second.second) / 2 + cnt * to.second.second;
    }
    if (now[v][0] != -1e9)
    ans += now[v][0] / 2;
    if (now[v][1] != -1e9)
    ans += (now[v][1] - cntt[v][1]) / 2 + cntt[v][1];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < N; i++) now[i][0] = now[i][1] = -1e9;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
	}
	cnt(1);
	fill(used.begin(), used.end(), 0);
	dfs(1);
	cout << ans << endl;
	return 0;
}