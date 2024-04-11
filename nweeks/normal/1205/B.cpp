#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXBIT = 60;
const int MAXN = 1e5;

vector<int> G[MAXN];
ll arr[MAXN];
int n;

int shortest_cycle(int s, int t)
{
	queue<int> Q;
	Q.push(s);
	vector<int> dis(n,1e9);

	dis[s] = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (u == t)
			return dis[t]+1;
		for (auto v : G[u])
			if ((u != s or v != t) and dis[v] == 1e9)
			{
				dis[v] = dis[u]+1;
				Q.push(v);
			}
	}
	return 1e9;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> arr[i];
	vector<ll> cpy;
	for (int i(0); i < n; ++i)
		if (arr[i])
			cpy.push_back(arr[i]);
	n = SZ(cpy);
	for (int i(0); i < n; ++i)
		arr[i] = cpy[i];
	if (n > 2*MAXBIT)
	{
		cout << 3 << endl;
		return 0;
	}

	for (int i(0); i < n; ++i)
		for (int j(i+1); j < n; ++j)
			if (arr[i] & arr[j])
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
	int ans(1e9);
	for (int i(0); i < n; ++i)
		for (int j(i+1); j < n; ++j)
			if (arr[i]&arr[j])
				ans = min(ans, shortest_cycle(i,j));
	if (ans == 1e9) ans = -1;
	cout << ans << endl;
}