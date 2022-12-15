#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e3;

vector<int> G[MAXN];
ll cnt[MAXN];

ll get_ans(int node)
{
	fill(cnt, cnt + MAXN, 0);
	ll ans(0);
	for (auto v : G[node])
		for (auto vv : G[v])
			cnt[vv]++;
	for (int i(0); i < MAXN; ++i)
		if (i != node)
			ans += (cnt[i] * (cnt[i]-1))/2;
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;

	for (int i(0); i < M; ++i)
	{
		int u, v; cin >> u >> v;
		G[u-1].push_back(v-1);
	}

	ll ans(0);
	for (int i(0); i < N; ++i)
		ans += get_ans(i);
	cout << ans << endl;
}