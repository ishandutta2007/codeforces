#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
const int MAXA = 1 << 13;
int a[MAXN];
int lowest[MAXA];
vector<int> check[MAXA];

void update(int num, int val)
{
	while (lowest[num] > val)
	{
		check[lowest[num]].push_back(num);
		lowest[num]--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(lowest, lowest + MAXA, MAXA - 1);
	update(0, -1);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int x : check[a[i]])
		{
			update(x ^ a[i], a[i]);
		}
		check[a[i]].clear();
	}
	vector<int> ans;
	for (int i = 0; i < MAXA; i++)
	{
		if (lowest[i] < MAXA - 1)
			ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int x : ans)
		cout << x << " ";
	cout << "\n";
	return 0;
}