#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 1e5;

int cur_time=0;
vector<int> G[MAXN];
vector<pair<int, int> > ops;

void solve(int u, int p, int exit = -1)
{
	//cout << "(" << u+1 << ' ' << exit << ")" << endl;
	ops.emplace_back(u+1, cur_time++);
	//cout << u + 1 << ' ' << cur_time++ << endl;
	int nb_restants(SZ(G[u]) - (u!=p));
	for (auto v : G[u])
		if (v != p)
		{
			if (cur_time > SZ(G[u]))
			{
				int reset = (exit == -1 ? 0 : exit - nb_restants);
				assert(reset >= 0);
				if (reset != cur_time-1)
					ops.emplace_back(u+1, reset);
				//cout << u + 1 << ' ' << reset << endl;
				cur_time = reset+1;
			}
			solve(v, u, cur_time-1);
			//cout << u+1 << ' ' << cur_time++ << endl;
			ops.emplace_back(u+1, cur_time++);
			--nb_restants;
		}
	if (exit != -1)
	{
		if (cur_time != exit+1)
			ops.emplace_back(u+1, exit);
		//cout << u+1 << ' ' << exit << '\n';
		cur_time = exit+1;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_sommets;
	cin >> nb_sommets;
	for (int i(1); i < nb_sommets; ++i)
		{
			int _u, _v;
			cin >> _u >> _v;
			--_u, --_v;
			G[_u].push_back(_v);
			G[_v].push_back(_u);
		}
	solve(0,0);
	cout << SZ(ops) << endl;
	for (auto [u, t] : ops)
		cout << u << ' ' << t << '\n';
}