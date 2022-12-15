#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;

int c[MAX];
set<int> card[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i(0); i < N; ++i)
		cin >> c[i];
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (c[a]!=c[b])
			card[c[a]].insert(c[b]), card[c[b]].insert(c[a]);
	}

	int ans(c[0]);
	for (int i(1); i < N; ++i)
	{
		if (card[c[i]].size() == card[ans].size() and c[i]<ans)
			ans = c[i];
		else if (card[c[i]].size() > card[ans].size())
			ans = c[i];
	}
	cout << ans<< endl;
}