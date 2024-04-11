#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick
{
	int N;
	vector<int> BIT;

	Fenwick(int n) { N = n+1; BIT.assign(N, 0); }

	void change(int i, int x)
	{
		for (i++; i < N; i += i & -i)
			BIT[i] = max(x, BIT[i]);
	}

	int get_max(int r)
	{
		int mx(0);
		for (r++; r; r -= r & -r)
			mx = max(mx, BIT[r]);
		return mx;
	}
};

int solve(void)
{
	int nbElem;
	cin >> nbElem;

	deque<int> arr(nbElem+1);
	for (int i(1); i <= nbElem; ++i)
		cin >> arr[i];
	nbElem++;

	Fenwick fen(nbElem);
	vector<int> dp(nbElem);
	vector<int> nxt(nbElem);
	vector<vector<pair<int, int>>> update(nbElem);
	for (int i(nbElem-1); i >= 0; --i)
	{
		nxt[i] = i+1;
		while (nxt[i] < nbElem and arr[nxt[i]] <= arr[i])
			nxt[i] = nxt[nxt[i]];
	}
	for (int i(0); i < nbElem; ++i)
	{
		dp[i] = fen.get_max(arr[i]) + 1;
		if (nxt[i] < nbElem)
			update[nxt[i]].emplace_back(arr[i], dp[i] + 1);
		fen.change(arr[i], dp[i]);
		for (auto p : update[i])
			fen.change(p.first, p.second);
	}
	return fen.get_max(nbElem-1)-1;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}