#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 3000;

string dir;
vector<vector<int>> optimal_moves;
int tot(0);
int n, k;

bool simulate(void)
{
	int i(0);
	vector<int> m;
	while (i < n)
	{
		if (i+1 < n and dir[i] == 'R' and dir[i+1] == 'L')
		{
			dir[i] = 'L';
			dir[i+1] = 'R';
			m.push_back(i+1);
			++i;
			++tot;
		}
		++i;
	}
	if (SZ(m) > 0)
		optimal_moves.push_back(m);
	
	return SZ(m) > 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	cin >> dir;
	
	while (simulate());
	
	if (SZ(optimal_moves) > k or tot < k)
	{
		cout << -1 << endl;
		return 0;
	}
	
	int to_add(k - SZ(optimal_moves));
	vector<vector<int> > sol;

	for (int i(0); i < SZ(optimal_moves); ++i)
	{
		while (to_add> 0 and SZ(optimal_moves[i]) > 1)
		{
			to_add--;
			sol.push_back({optimal_moves[i].back()});
			optimal_moves[i].pop_back();
		}
		sol.push_back(optimal_moves[i]);
	}
	assert(SZ(sol) == k);
	for (int i(0); i < k; ++i)
	{
		cout << SZ(sol[i]) << ' ';
		for (auto s : sol[i])
			cout << s << ' ';
		cout << '\n';
	}
}