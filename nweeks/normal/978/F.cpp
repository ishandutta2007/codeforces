#include <bits/stdc++.h>
using namespace std;

struct Worker
{
	int skill, id;

	bool operator<(Worker other) const
	{
		return skill < other.skill;
	}
};

const int MAXN = 2e5;

Worker workers[MAXN];
stack<int> to_rem;
bool passed[MAXN];
int ans[MAXN];
vector<int> G[MAXN];

int N, k;

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	cin >> N >> k;
	for (int i(0); i < N; ++i)
	{
		cin >> workers[i].skill;
		workers[i].id = i;
	}
	for (int i(0); i < k; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sort(workers, workers + N);
	
	int cnt(0);

	for (int i(0); i < N; ++i)
	{
		while (!to_rem.empty() and workers[to_rem.top()].skill < workers[i].skill)
		{
			++cnt;
			passed[workers[to_rem.top()].id] = true;
			to_rem.pop();
		}
		ans[workers[i].id] = cnt;
		for (auto v : G[workers[i].id])
			if (passed[v])
				--ans[workers[i].id];
		to_rem.push(i);
	}
	for (int i(0); i < N; ++i)
		cout << ans[i] << ' ';
}