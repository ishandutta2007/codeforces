#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;
const int N = 26;
set<int> G[27];

void solve(void)
{
	string s;
	cin >> s;
	int n = s.size();
	for (int i(0); i < 26; ++i)
		G[i].clear();

	for (int i(0); i < n-1; ++i)
	{
		int u = s[i]-'a';
		int v = s[i+1]-'a';
		G[u].insert(v);
		G[v].insert(u);
	}

	for (int i(0); i < N; ++i)
		if (G[i].size() > 2)
		{
			cout << "NO" << '\n';
			return ;
		}
	string order = "";
	vector<int> state(26);
	
	for (int i(0); i  < 26; ++i)
	{
		if (state[i] == 2)
			continue;
		if (G[i].size() == 0)
		{
			order += (char)(i + 'a');
			state[i] = 2;
			continue ;
		}
		if (G[i].size() > 1)
			continue ;
		
		state[i] = 2;
		order += (char)(i + 'a');
		int cur = *G[i].begin();
		int prev = i;
		while (1)
		{
			if (state[cur])
			{
				cout << "NO" << '\n';
				return ;
			}
			state[cur] = 2;
			order += (char)(cur+'a');
			if (G[cur].size() == 1)
				break;
			int nxt(-1);
			for (auto v : G[cur])
				if (v != prev)
					nxt = v;
			prev = cur;
			cur = nxt;
		}
	}
	if (order.size() != 26)
		cout << "NO" << '\n';
	else
		cout << "YES\n" << order << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}